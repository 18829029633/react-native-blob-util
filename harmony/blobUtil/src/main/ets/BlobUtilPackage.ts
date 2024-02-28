import {RNPackage, TurboModulesFactory} from 'rnoh/ts';
import type {TurboModule, TurboModuleContext} from 'rnoh/ts';
import {BlobUtilTurboModule} from './BlobUtilTurboModule';

class BlobUtilTurboModulesFactory extends TurboModulesFactory {
  createTurboModule(name: string): TurboModule | null {
    if (name === 'BlobUtilTurboModule' || name === "GeneratedBlobUtilTurboModule") {
      return new BlobUtilTurboModule(this.ctx);
    }
    return null;
  }

  hasTurboModule(name: string): boolean {
    return name === 'BlobUtilTurboModule' || name === "GeneratedBlobUtilTurboModule";
  }
}

export class BlobUtilPackage extends RNPackage {
  createTurboModulesFactory(ctx: TurboModuleContext): TurboModulesFactory {
    return new BlobUtilTurboModulesFactory(ctx);
  }
}
