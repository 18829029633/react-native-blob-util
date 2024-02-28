import HashMap from '@ohos.util.HashMap';
import common from '@ohos.app.ability.common';
import fs, { Options } from '@ohos.file.fs';
import { ReactNativeBlobUtilConst } from '../utils/ReactNativeBlobUtilConst';
import { BusinessError } from '@ohos.base';
import { ArrayList } from '@kit.ArkTS';

export default class ReactNativeBlobUtilFS {

  private context: common.UIAbilityContext | undefined = undefined;

  constructor(context:common.UIAbilityContext) {
    this.context = context;
  }

  getSystemFolders():object{
    let res = new HashMap<string, Object>();
    res.set('CacheDir',this.context.cacheDir);
    res.set('DocumentDir',this.context.filesDir);
    //下载的标准目录
    res.set('DownloadDir',this.context.filesDir);
    //应用安装后的app的hap资源包所在目录
    res.set('MainBundleDir',this.context.bundleCodeDir)
    //电影存放路径
    res.set('MovieDir',this.context.filesDir+'/movie')
    //音乐存放路径
    res.set('MusicDir',this.context.filesDir+'/music')
    //图片存放路径
    res.set('PictureDir',this.context.filesDir+'/picture')

    res.set("ApplicationSupportDir", "");
    res.set("RingtoneDir", "");
    res.set("SDCardDir", "");
    res.set("SDCardApplicationDir", "");
    res.set("DCIMDir", "");

    res.set("LegacyDCIMDir", "");
    res.set("LegacyPictureDir", "");
    res.set("LegacyMusicDir", "");
    res.set("LegacyDownloadDir", "");
    res.set("LegacyMovieDir", "");
    res.set("LegacyRingtoneDir", "");
    res.set("LegacySDCardDir", "");

    const entriesArray = Array.from(res.entries());
    // 将数组转换为对象
    const myObject = entriesArray.reduce((acc, [key, value]) => {
      acc[key] = value;
      return acc;
    }, {});
    return myObject;
  }

  createFile(path:string,data:string,encoding:string):Promise<string> {
    return new Promise((resolve,reject) => {
      let filesDir = this.context.cacheDir;
      let id = path.split('/').pop();
      let newPath = `${filesDir}/${id}`;
      //同步形式检查文件是否存在
      let created = fs.accessSync(newPath)
      if(encoding === ReactNativeBlobUtilConst.DATA_ENCODE_URI) {
        let orgPath = data.replace(ReactNativeBlobUtilConst.FILE_PREFIX, "");
        if(!fs.accessSync(orgPath)) {
          reject("Source file : " + data + " does not exist")
        }
        let file = fs.openSync(orgPath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
        try {
          fs.copyFile(file.fd,newPath);
        } catch (err) {
          reject(`copyFileToCache copyFileSync err = ${err}`)
        }
        fs.close(file.fd);
      } else {
        if(created) {
          reject("File `" + path + "` already exists");
          return;
        }
        let file = fs.openSync(newPath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
        let options: Options = {
          encoding: 'utf-8'
        };
        fs.writeSync(file.fd,data,options)
        fs.close(file.fd);
        resolve(newPath)
      }
    });
  }

  stat(path:string,callback: (err:any,stat:any) => void) {
    fs.stat(path, (err, stat) => {
      if (err) {
        callback("failed to stat path `" + path + "` because it does not exist or it is not a folder",null)
      } else {
        let filename = path.split('/').pop();
        let statObj = {
          'filename':filename,
          'path':path,
          'type':'asset',
          'size':stat.size,
          'lastModified':stat.mtime
        }
        callback(null,statObj)
      }
    });
  }

  unlink(path:string){
    fs.unlink(path, (err) => {
      if (err) {
        console.error("remove file failed with error message: " + err.message );
      } else {
        console.info("remove file succeed");
      }
    });
  }

  copyFileToCache(path: string,cacheDir: string,callback: (err:any,res:any) => void) {
    // let id = cacheDir.split('/').pop();
    // let imagePath = `${cacheDir}/${id}`;
    if(fs.accessSync(cacheDir)){
      fs.openSync(cacheDir, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
      //callback("Destination file at '" + cacheDir + "' already exists",false)
    }
    let file =  fs.openSync(path);
   // let file = fs.openSync(imagePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
    try {
      fs.copyFileSync(file.fd, cacheDir);
    } catch (err) {
      callback(`copyFileToCache copyFileSync err = ${err}`,false)
    }
    fs.closeSync(file.fd);
    callback(null,true)
  }



  writeFile(path: string,encoding: string,data: string ,transformFile: boolean, append: boolean):Promise<number> {
    return new Promise((resolve,reject) => {
      let file = fs.openSync(path, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
      let writeLen = fs.writeSync(file.fd, data);
      if(writeLen==-1){
        console.log("write data to file succeed and size is:" + writeLen)
      }else{
        console.log('success')
      }
      fs.closeSync(file);
    })
  }

  writeFileArray(path:string,data:Array<number>,append:boolean):Promise<number> {
    return new Promise((resolve,reject) => {
      let file = fs.openSync(path, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
      let buffer = new Uint8Array(data).buffer
      fs.write(file.fd,buffer, (err, writeLen) => {
        if (err) {
          reject(-1);
          console.error("write failed with error message: " + err.message + ", error code: " + err.code);
        } else {
          console.info("write data to file succeed and size is:" + writeLen);
          resolve(writeLen);
          fs.closeSync(file);
        }
      });
      fs.closeSync(file);
    })
  }

  //创建文件
  mkdir(path: string): Promise<void> {
    return new Promise(async (resolve, reject) => {
      fs.mkdir(path, true, (err: BusinessError) => {
        if (err) {
          if (err.code == 13900015) {
            // 文件夹存在
            resolve();
          } else {
            reject(`Directory could not be created ${err.message} ${err.code}`);
          }
        } else {
          resolve();
        }
      })
    })
  }
}