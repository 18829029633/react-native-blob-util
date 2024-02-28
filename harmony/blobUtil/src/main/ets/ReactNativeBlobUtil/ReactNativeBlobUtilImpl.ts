import common from '@ohos.app.ability.common';
import { TurboModuleContext } from 'rnoh/ts';
import ReactNativeBlobUtilFS from './ReactNativeBlobUtilFS';
import ReactNativeBlobUtilStream from './ReactNativeBlobUtilStream';
import { AsyncCallback } from '@ohos.base';

export default class ReactNativeBlobUtilImpl {

  private context: common.UIAbilityContext | undefined = undefined;

  private reactNativeBlobUtilFS:ReactNativeBlobUtilFS | undefined= undefined

  private reactNativeBlobUtilStream:ReactNativeBlobUtilStream | undefined = undefined

  private ctx: TurboModuleContext | undefined = undefined

  constructor(context: common.UIAbilityContext,ctx: TurboModuleContext) {
    this.context = context
    this.ctx = ctx
    this.reactNativeBlobUtilFS = new ReactNativeBlobUtilFS(context)
    this.reactNativeBlobUtilStream = new ReactNativeBlobUtilStream(this.ctx)
  }

  getSystemFolders() {
    return this.reactNativeBlobUtilFS.getSystemFolders()
  }

  createFile(path: string, data: string, encoding: string):Promise<string> {
    return this.reactNativeBlobUtilFS.createFile(path,data,encoding)
  }

  writeStream(path: string, encoding: string, appendData: boolean, callback: (errCode,errMsg,streamId?:string) => void) {
    this.reactNativeBlobUtilStream.writeStream(path,encoding,appendData,callback);
  }

  readStream(filePath:string,encoding:string,bufferSize:number,tick?:number,streamId?:string):Promise<string>{
    return this.reactNativeBlobUtilStream.readStream(filePath,encoding,bufferSize,tick,streamId);
  }

  stat(path:string,callback: (err:any,stat:any) => void){
    this.reactNativeBlobUtilFS.stat(path,callback)
  }

  cp(path: string,cacheDir: string,callback: (err:any,res:any) => void) {
    this.reactNativeBlobUtilFS.copyFileToCache(path,cacheDir,callback)
  }


  writeFile(path: string, encoding: string, data: string, transformFile: boolean, append: boolean):Promise<number>{
    return this.reactNativeBlobUtilFS.writeFile(path,encoding,data,transformFile,append)
  }

  writeFileArray(path: string,data:Array<number>,append: boolean):Promise<number> {
    return this.reactNativeBlobUtilFS.writeFileArray(path,data,append)
  }

  unlink(path:string){
    this.reactNativeBlobUtilFS.unlink(path)
  }

  mkdir(path:string):Promise<void>{
    return this.reactNativeBlobUtilFS.mkdir(path)
  }
}