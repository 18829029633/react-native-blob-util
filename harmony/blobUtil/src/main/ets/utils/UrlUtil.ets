import common from '@ohos.app.ability.common';
import preferences from '@ohos.data.preferences';
import { DEFAULT } from '@ohos/hypium';

const TAG: string = 'UrlUtils';
const URL_KEY: string = 'url';
const STORE_NAME: string = 'server_url';

class UrlUtil {

  async getUrl(context: common.UIAbilityContext): Promise<string> {
    let preference = await preferences.getPreferences(context, STORE_NAME);
    let url = await preference.get(URL_KEY, '') as string;
    console.info(TAG, `getUrl,url= ${url}`);
    return url;
  }

  async saveUrl(context: common.UIAbilityContext, url: string) {
    let preference = await preferences.getPreferences(context, STORE_NAME);
    await preference.put(URL_KEY, url);
    await preference.flush();
  }
}

export const urlUtil = new UrlUtil();