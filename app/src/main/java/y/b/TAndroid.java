package y.b;

import android.os.Build.VERSION;

public class TAndroid
{
    public TWrapper w;

    public TAndroid(TWrapper w)
    {
        this.w = w;
    }

    public int getAPINumber()
    {
        int ret = VERSION.SDK_INT;
//        String sSDK = VERSION.SDK;
//
//        if (sSDK.equals("BASE")) {
//            ret = 1;
//        } else if (sSDK.equals("BASE_1_1")) {
//            ret = 2;
//        } else if (sSDK.equals("CUPCAKE")) {
//            ret = 3;
//        }
        return ret;
    }
}
