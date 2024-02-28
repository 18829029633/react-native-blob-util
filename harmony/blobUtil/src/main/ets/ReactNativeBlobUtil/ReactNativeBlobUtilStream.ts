
import fs, { Options } from '@ohos.file.fs';
import emitter from '@ohos.events.emitter'
import util from '@ohos.util';
import HashMap from '@ohos.util.HashMap';
import { ReactNativeBlobUtilConst } from '../utils/ReactNativeBlobUtilConst';
import common from '@ohos.app.ability.common';
import { EventEmitter,Descriptor,TurboModuleContext } from 'rnoh/ts';
export type BlobUtilViewDescriptor = Descriptor<"RNCBlobUtil">
export const FAST_BLOB_UTIL = "BlobUtil"

export default class ReactNativeBlobUtilStream {

  private ctx: TurboModuleContext | undefined = undefined
  private stream:fs.Stream | undefined = undefined;
  private encoding:string = 'base64'
  private static fileStreams = new HashMap<string, ReactNativeBlobUtilStream>();
  private descriptor: BlobUtilViewDescriptor = {} as BlobUtilViewDescriptor

  constructor(ctx: TurboModuleContext) {
    this.ctx = ctx;
  }


  async writeStream(filePath: string, encoding: string,append:boolean, callback: (errCode,errMsg,streamId?:string) => void) {
    if(!fs.accessSync(filePath)){
      callback("ENOENT", "File '" + filePath + "' does not exist and could not be created");
      return
    }
    let file = fs.openSync(filePath);
    this.encoding = encoding;
    try {
      let stream = await fs.fdopenStream(file.fd,"r+")
      let uuid = util.generateRandomUUID(true);
      ReactNativeBlobUtilStream.fileStreams.set(uuid,this)
      this.stream = stream
      fs.closeSync(file);
      callback(null,null,uuid)
      console.log('writeStream finish----------', uuid)
    } catch (err) {
      console.log('writeStream exception----------', err)
      callback("EUNSPECIFIED", "Failed to create write stream at path `" + filePath + "`; " + err.message);
    }
  }

  readStream(filePath:string,encoding:string,bufferSize:number,tick?:number,streamId?:string) :Promise<string>{
    return new Promise((resolve,reject)=>{
      let inputStream = fs.createStreamSync(filePath, 'r+');
      if(encoding.toLowerCase() === 'utf8') {
        let buf = new ArrayBuffer(bufferSize);
        let readSize = 0;
        let readLen = inputStream.readSync(buf, { offset: readSize });
        readSize += readLen;
        while (readLen > 0) {
          let content = String.fromCharCode.apply(null, new Uint8Array(buf))
          this.emitStreamEvent(streamId,'data',content);
          readLen = inputStream.readSync(buf, { offset: readSize });
          readSize += readLen
        }
        inputStream.closeSync();
      }
      resolve('1111111')
    })
  }

  emitStreamEvent(streamName:string,event:string,data:string) {
    this.ctx.rnInstance.emitComponentEvent(
      this.descriptor.tag,
      FAST_BLOB_UTIL,
      {
        type: "ReactNativeBlobUtilFilesystem",
      }
    );
  }

}