//
// Created on 2024/1/31.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".


#include "BlobUtilTurboModule.h"
#include "RNOH/ArkTSTurboModule.h"

using namespace rnoh;
using namespace facebook;

static jsi::Value __hostFunction_BlobUtilTurboModule_createFile(jsi::Runtime &rt, react::TurboModule &turboModule,
                                                                const jsi::Value *args, size_t count) {
    return static_cast<ArkTSTurboModule &>(turboModule).callAsync(rt, "createFile", args, count);
}

static jsi::Value __hostFunction_BlobUtilTurboModule_getConstants(jsi::Runtime &rt, react::TurboModule &turboModule,
                                                                const jsi::Value *args, size_t count) {
    return static_cast<ArkTSTurboModule &>(turboModule).call(rt, "getConstants", args, count);
}
static jsi::Value __hostFunction_BlobUtilTurboModule_createFileASCII(jsi::Runtime &rt, react::TurboModule &turboModule,
                                                                     const jsi::Value *args, size_t count) {
    return static_cast<ArkTSTurboModule &>(turboModule).callAsync(rt, "createFileASCII", args, count);
}
static jsi::Value __hostFunction_BlobUtilTurboModule_writeFile(jsi::Runtime &rt, react::TurboModule &turboModule,
                                                               const jsi::Value *args, size_t count) {
    return static_cast<ArkTSTurboModule &>(turboModule).callAsync(rt, "writeFile", args, count);
}
static jsi::Value __hostFunction_BlobUtilTurboModule_stat(jsi::Runtime &rt, react::TurboModule &turboModule,
                                                          const jsi::Value *args, size_t count) {
    return static_cast<ArkTSTurboModule &>(turboModule).call(rt, "stat", args, count);
}

static jsi::Value __hostFunction_BlobUtilTurboModule_cp(jsi::Runtime &rt, react::TurboModule &turboModule,
                                                        const jsi::Value *args, size_t count) {
    return static_cast<ArkTSTurboModule &>(turboModule).callAsync(rt, "cp", args, count);
}
static jsi::Value __hostFunction_BlobUtilTurboModule_writeFileArray(jsi::Runtime &rt, react::TurboModule &turboModule,
                                                                    const jsi::Value *args, size_t count) {
    return static_cast<ArkTSTurboModule &>(turboModule).callAsync(rt, "writeFileArray", args, count);
}
static jsi::Value __hostFunction_BlobUtilTurboModule_unlink(jsi::Runtime &rt, react::TurboModule &turboModule,
                                                            const jsi::Value *args, size_t count) {
    return static_cast<ArkTSTurboModule &>(turboModule).call(rt, "unlink", args, count);
}
static jsi::Value __hostFunction_BlobUtilTurboModule_writeStream(jsi::Runtime &rt, react::TurboModule &turboModule,
                                                                 const jsi::Value *args, size_t count) {
    return static_cast<ArkTSTurboModule &>(turboModule).call(rt, "writeStream", args, count);
}
static jsi::Value __hostFunction_BlobUtilTurboModule_mkdir(jsi::Runtime &rt, react::TurboModule &turboModule,
                                                                 const jsi::Value *args, size_t count) {
    return static_cast<ArkTSTurboModule &>(turboModule).call(rt, "mkdir", args, count);
}

//下面接口还未实现
static jsi::Value __hostFunction_BlobUtilTurboModule_pathForAppGroup(jsi::Runtime &rt, react::TurboModule &turboModule,
                                                                     const jsi::Value *args, size_t count) {
    return static_cast<ArkTSTurboModule &>(turboModule).callAsync(rt, "pathForAppGroup", args, count);
}
static jsi::Value __hostFunction_BlobUtilTurboModule_syncPathAppGroup(jsi::Runtime &rt, react::TurboModule &turboModule,
                                                                     const jsi::Value *args, size_t count) {
    return static_cast<ArkTSTurboModule &>(turboModule).callAsync(rt, "syncPathAppGroup", args, count);
}

static jsi::Value __hostFunction_BlobUtilTurboModule_ls(jsi::Runtime &rt, react::TurboModule &turboModule,
                                                                    const jsi::Value *args, size_t count) {
    return static_cast<ArkTSTurboModule &>(turboModule).callAsync(rt, "ls", args, count);
}
static jsi::Value __hostFunction_BlobUtilTurboModule_readFile(jsi::Runtime &rt, react::TurboModule &turboModule,
                                                           const jsi::Value *args, size_t count) {
    return static_cast<ArkTSTurboModule &>(turboModule).callAsync(rt, "readFile", args, count);
}
static jsi::Value __hostFunction_BlobUtilTurboModule_hash(jsi::Runtime &rt, react::TurboModule &turboModule,
                                                              const jsi::Value *args, size_t count) {
    return static_cast<ArkTSTurboModule &>(turboModule).callAsync(rt, "hash", args, count);
}
static jsi::Value __hostFunction_BlobUtilTurboModule_enableProgressReport(jsi::Runtime &rt, react::TurboModule &turboModule,
                                                                const jsi::Value *args, size_t count) {
    return static_cast<ArkTSTurboModule &>(turboModule).call(rt, "enableProgressReport", args, count);
}
static jsi::Value __hostFunction_BlobUtilTurboModule_enableUploadProgressReport(jsi::Runtime &rt,
                                                                          react::TurboModule &turboModule,
                                                                          const jsi::Value *args, size_t count) {
    return static_cast<ArkTSTurboModule &>(turboModule).call(rt, "enableUploadProgressReport", args, count);
}
static jsi::Value __hostFunction_BlobUtilTurboModule_slice(jsi::Runtime &rt, react::TurboModule &turboModule,const jsi::Value *args, size_t count) {
    return static_cast<ArkTSTurboModule &>(turboModule).callAsync(rt, "slice", args, count);
}
static jsi::Value __hostFunction_BlobUtilTurboModule_presentOptionsMenu(jsi::Runtime &rt, react::TurboModule &turboModule,
                                                                      const jsi::Value *args, size_t count) {
    return static_cast<ArkTSTurboModule &>(turboModule).callAsync(rt, "presentOptionsMenu", args, count);
}
static jsi::Value __hostFunction_BlobUtilTurboModule_presentOpenInMenu(jsi::Runtime &rt,
                                                                        react::TurboModule &turboModule,
                                                                        const jsi::Value *args, size_t count) {
    return static_cast<ArkTSTurboModule &>(turboModule).callAsync(rt, "presentOpenInMenu", args, count);
}
static jsi::Value __hostFunction_BlobUtilTurboModule_presentPreview(jsi::Runtime &rt,
                                                                       react::TurboModule &turboModule,
                                                                       const jsi::Value *args, size_t count) {
    return static_cast<ArkTSTurboModule &>(turboModule).callAsync(rt, "presentPreview", args, count);
}
static jsi::Value __hostFunction_BlobUtilTurboModule_excludeFromBackupKey(jsi::Runtime &rt, react::TurboModule &turboModule,
                                                                    const jsi::Value *args, size_t count) {
    return static_cast<ArkTSTurboModule &>(turboModule).callAsync(rt, "excludeFromBackupKey", args, count);
}
static jsi::Value __hostFunction_BlobUtilTurboModule_actionViewIntent(jsi::Runtime &rt,
                                                                          react::TurboModule &turboModule,
                                                                          const jsi::Value *args, size_t count) {
    return static_cast<ArkTSTurboModule &>(turboModule).callAsync(rt, "actionViewIntent", args, count);
}
static jsi::Value __hostFunction_BlobUtilTurboModule_addCompleteDownload(jsi::Runtime &rt, react::TurboModule &turboModule,
                                                                      const jsi::Value *args, size_t count) {
    return static_cast<ArkTSTurboModule &>(turboModule).callAsync(rt, "addCompleteDownload", args, count);
}
static jsi::Value __hostFunction_BlobUtilTurboModule_copyToInternal(jsi::Runtime &rt,
                                                                         react::TurboModule &turboModule,
                                                                         const jsi::Value *args, size_t count) {
    return static_cast<ArkTSTurboModule &>(turboModule).callAsync(rt, "copyToInternal", args, count);
}
static jsi::Value __hostFunction_BlobUtilTurboModule_copyToMediaStore(jsi::Runtime &rt, react::TurboModule &turboModule,
                                                                    const jsi::Value *args, size_t count) {
    return static_cast<ArkTSTurboModule &>(turboModule).callAsync(rt, "copyToMediaStore", args, count);
}
static jsi::Value __hostFunction_BlobUtilTurboModule_createMediaFile(jsi::Runtime &rt, react::TurboModule &turboModule,
                                                                      const jsi::Value *args, size_t count) {
    return static_cast<ArkTSTurboModule &>(turboModule).callAsync(rt, "createMediaFile", args, count);
}
static jsi::Value __hostFunction_BlobUtilTurboModule_getBlob(jsi::Runtime &rt, react::TurboModule &turboModule,
                                                                     const jsi::Value *args, size_t count) {
    return static_cast<ArkTSTurboModule &>(turboModule).callAsync(rt, "getBlob", args, count);
}
static jsi::Value __hostFunction_BlobUtilTurboModule_getContentIntent(jsi::Runtime &rt, react::TurboModule &turboModule,
                                                             const jsi::Value *args, size_t count) {
    return static_cast<ArkTSTurboModule &>(turboModule).callAsync(rt, "getContentIntent", args, count);
}
static jsi::Value __hostFunction_BlobUtilTurboModule_getSDCardDir(jsi::Runtime &rt, react::TurboModule &turboModule,
                                                                      const jsi::Value *args, size_t count) {
    return static_cast<ArkTSTurboModule &>(turboModule).callAsync(rt, "getSDCardDir", args, count);
}
static jsi::Value __hostFunction_BlobUtilTurboModule_getSDCardApplicationDir(jsi::Runtime &rt, react::TurboModule &turboModule,
                                                                  const jsi::Value *args, size_t count) {
    return static_cast<ArkTSTurboModule &>(turboModule).callAsync(rt, "getSDCardApplicationDir", args, count);
}
static jsi::Value __hostFunction_BlobUtilTurboModule_writeToMediaFile(jsi::Runtime &rt,
                                                                             react::TurboModule &turboModule,
                                                                             const jsi::Value *args, size_t count) {
    return static_cast<ArkTSTurboModule &>(turboModule).callAsync(rt, "writeToMediaFile", args, count);
}
static jsi::Value __hostFunction_BlobUtilTurboModule_addListener(jsi::Runtime &rt, react::TurboModule &turboModule,
                                                                 const jsi::Value *args, size_t count) {
    return static_cast<ArkTSTurboModule &>(turboModule).call(rt, "addListener", args, count);
}
static jsi::Value __hostFunction_BlobUtilTurboModule_removeListeners(jsi::Runtime &rt, react::TurboModule &turboModule,
                                                                 const jsi::Value *args, size_t count) {
    return static_cast<ArkTSTurboModule &>(turboModule).call(rt, "removeListeners", args, count);
}
static jsi::Value __hostFunction_BlobUtilTurboModule_exists(jsi::Runtime &rt, react::TurboModule &turboModule,
                                                                     const jsi::Value *args, size_t count) {
    return static_cast<ArkTSTurboModule &>(turboModule).call(rt, "exists", args, count);
}
static jsi::Value __hostFunction_BlobUtilTurboModule_scanFile(jsi::Runtime &rt, react::TurboModule &turboModule,
                                                            const jsi::Value *args, size_t count) {
    return static_cast<ArkTSTurboModule &>(turboModule).call(rt, "scanFile", args, count);
}
static facebook::jsi::Value __hostFunction_NativeBlobUtilsSpecJSI_fetchBlobForm(jsi::Runtime &rt,
                                                                                react::TurboModule &turboModule,
                                                                                const jsi::Value *args, size_t count) {
    return static_cast<ArkTSTurboModule &>(turboModule).call(rt, "fetchBlobForm", args, count);
}
static jsi::Value __hostFunction_BlobUtilTurboModule_readStream(jsi::Runtime &rt, react::TurboModule &turboModule,
                                                                const jsi::Value *args, size_t count) {
    return static_cast<ArkTSTurboModule &>(turboModule).callAsync(rt, "readStream", args, count);
}



BlobUtilTurboModule::BlobUtilTurboModule(const ArkTSTurboModule::Context ctx, const std::string name)
    : ArkTSTurboModule(ctx, name) {
    methodMap_["createFile"] = MethodMetadata{3, __hostFunction_BlobUtilTurboModule_createFile};
    methodMap_["getConstants"] = MethodMetadata{0, __hostFunction_BlobUtilTurboModule_getConstants};
    methodMap_["writeFile"] = MethodMetadata{5, __hostFunction_BlobUtilTurboModule_writeFile};
    methodMap_["stat"] = MethodMetadata{2, __hostFunction_BlobUtilTurboModule_stat};
    methodMap_["cp"] = MethodMetadata{3, __hostFunction_BlobUtilTurboModule_cp};
    methodMap_["unlink"] = MethodMetadata{2, __hostFunction_BlobUtilTurboModule_unlink};
    methodMap_["mkdir"] = MethodMetadata{2, __hostFunction_BlobUtilTurboModule_mkdir};

    // 下面接口还未实现
    methodMap_["writeStream"] = MethodMetadata{4, __hostFunction_BlobUtilTurboModule_writeStream};
    methodMap_["createFileASCII"] = MethodMetadata{2, __hostFunction_BlobUtilTurboModule_createFileASCII};
    methodMap_["pathForAppGroup"] = MethodMetadata{1, __hostFunction_BlobUtilTurboModule_pathForAppGroup};
    methodMap_["syncPathAppGroup"] = MethodMetadata{1, __hostFunction_BlobUtilTurboModule_syncPathAppGroup};
    methodMap_["writeFileArray"] = MethodMetadata{3, __hostFunction_BlobUtilTurboModule_writeFileArray};
    methodMap_["ls"] = MethodMetadata{1, __hostFunction_BlobUtilTurboModule_ls};
    methodMap_["readFile"] = MethodMetadata{3, __hostFunction_BlobUtilTurboModule_readFile};
    methodMap_["hash"] = MethodMetadata{2, __hostFunction_BlobUtilTurboModule_hash};
    methodMap_["enableProgressReport"] = MethodMetadata{3, __hostFunction_BlobUtilTurboModule_enableProgressReport};
    methodMap_["enableUploadProgressReport"] = MethodMetadata{3, __hostFunction_BlobUtilTurboModule_enableUploadProgressReport};
    methodMap_["slice"] = MethodMetadata{4, __hostFunction_BlobUtilTurboModule_slice};
    methodMap_["presentOptionsMenu"] = MethodMetadata{2, __hostFunction_BlobUtilTurboModule_presentOptionsMenu};
    methodMap_["presentOpenInMenu"] = MethodMetadata{2, __hostFunction_BlobUtilTurboModule_presentOpenInMenu};
    methodMap_["presentPreview"] = MethodMetadata{2, __hostFunction_BlobUtilTurboModule_presentPreview};
    methodMap_["excludeFromBackupKey"] = MethodMetadata{1, __hostFunction_BlobUtilTurboModule_excludeFromBackupKey};
    methodMap_["actionViewIntent"] = MethodMetadata{3, __hostFunction_BlobUtilTurboModule_actionViewIntent};
    methodMap_["addCompleteDownload"] = MethodMetadata{1, __hostFunction_BlobUtilTurboModule_addCompleteDownload};
    methodMap_["copyToInternal"] = MethodMetadata{2, __hostFunction_BlobUtilTurboModule_copyToInternal};
    methodMap_["copyToMediaStore"] = MethodMetadata{3, __hostFunction_BlobUtilTurboModule_copyToMediaStore};
    methodMap_["createMediaFile"] = MethodMetadata{2, __hostFunction_BlobUtilTurboModule_createMediaFile};
    methodMap_["getBlob"] = MethodMetadata{2, __hostFunction_BlobUtilTurboModule_getBlob};
    methodMap_["getContentIntent"] = MethodMetadata{1, __hostFunction_BlobUtilTurboModule_getContentIntent};
    methodMap_["getSDCardDir"] = MethodMetadata{0, __hostFunction_BlobUtilTurboModule_getSDCardDir};
    methodMap_["getSDCardApplicationDir"] = MethodMetadata{0, __hostFunction_BlobUtilTurboModule_getSDCardApplicationDir};
    methodMap_["writeToMediaFile"] = MethodMetadata{3, __hostFunction_BlobUtilTurboModule_writeToMediaFile};
    methodMap_["addListener"] = MethodMetadata{1, __hostFunction_BlobUtilTurboModule_addListener};
    methodMap_["removeListeners"] = MethodMetadata{1, __hostFunction_BlobUtilTurboModule_removeListeners};
    methodMap_["exists"] = MethodMetadata{2, __hostFunction_BlobUtilTurboModule_exists};
    methodMap_["scanFile"] = MethodMetadata{2, __hostFunction_BlobUtilTurboModule_scanFile};
    methodMap_["fetchBlobForm"] = MethodMetadata{7, __hostFunction_NativeBlobUtilsSpecJSI_fetchBlobForm};
    methodMap_["readStream"] = MethodMetadata{5, __hostFunction_BlobUtilTurboModule_readStream};
}