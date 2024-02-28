import { TurboModule, RNOHError,Descriptor } from 'rnoh/ts';
import ReactNativeBlobUtilFS from './ReactNativeBlobUtil/ReactNativeBlobUtilFS';
import common from '@ohos.app.ability.common';
import ReactNativeBlobUtilImpl from './ReactNativeBlobUtil/ReactNativeBlobUtilImpl';
import { AsyncCallback } from '@ohos.base';

export class BlobUtilTurboModule extends TurboModule {
  private context: common.UIAbilityContext = this.ctx.uiAbilityContext;
  private reactNativeBlobUtilImpl: ReactNativeBlobUtilImpl = new ReactNativeBlobUtilImpl(this.context,this.ctx)


  addListener(eventName: string): void {
    console.info('aaaaaaaaaaaaaaa' + eventName)
  }

  getConstants():Object{
    return this.reactNativeBlobUtilImpl.getSystemFolders();
  }

  createFile(path: string, data: string, encoding: string):Promise<string> {
    return this.reactNativeBlobUtilImpl.createFile(path,data,encoding)
  }

  stat(path:string,callback: (err:any,stat:any) => void) {
    this.reactNativeBlobUtilImpl.stat(path,callback)
  }

  cp(path:string,cacheDir:string,callback: (err:any,res:any) => void) {
    this.reactNativeBlobUtilImpl.cp(path,cacheDir,callback)
  }

  writeFile(path: string, encoding: string, data: string, transformFile: boolean, append: boolean):Promise<number> {
    return this.reactNativeBlobUtilImpl.writeFile(path,encoding,data,transformFile,append)
  }

  writeFileArray(path: string, data: Array<number>, appendData: boolean) {
    return this.reactNativeBlobUtilImpl.writeFileArray(path,data,appendData)
  }

  writeStream(path: string, encoding: string, appendData: boolean, callback: (errCode,errMsg,streamId?:string) => void) {
    this.reactNativeBlobUtilImpl.writeStream(path,encoding,appendData,callback)
  }

  readStream(path:string,encoding:string,bufferSize:number,tick?:number,streamId?:string):Promise<string> {
    return this.reactNativeBlobUtilImpl.readStream(path,encoding,bufferSize,tick,streamId)
  }

  unlink(path:string){
    this.reactNativeBlobUtilImpl.unlink(path)
  }

  mkdir(path:string):Promise<void>{
    return this.reactNativeBlobUtilImpl.mkdir(path)
  }
}
