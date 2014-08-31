package z.a;

import android.Manifest;
import android.content.Context;
import android.content.pm.PackageManager;
import android.os.Binder;
import android.os.Build.VERSION;

public class TAndroid
{
	public TWrapper w;

    public TAndroid(TWrapper w)
    {
    	this.w = w;
    }

	public int getAPI00Number()
	{
		int ret = VERSION.SDK_INT;
		String sSDK = VERSION.SDK;

		if (sSDK.equals("BASE")) {
			ret = 1;
		} else if (sSDK.equals("BASE_1_1")) {
			ret = 2;
		} else if (sSDK.equals("CUPCAKE")) {
			ret = 3;
		}
        return ret;
	}

	public boolean isSystem()
	{
		int ok = PackageManager.PERMISSION_GRANTED;
		Context c = w.context;
		PackageManager pm = w.context.getPackageManager();

		String permission = Manifest.permission.WRITE_SECURE_SETTINGS;

		String pname = c.getPackageName();
		int uid = Binder.getCallingUid();
		String uidname  = pm.getNameForUid(uid);

		int r1 = c.checkCallingOrSelfPermission(permission);
		int r2 = pm.checkPermission(permission, pname);
		int r3 = pm.checkPermission(permission, uidname);

		boolean ret = false;

		ret |= (r1 == ok);
		ret |= (r2 == ok);
		ret |= (r3 == ok);

		return ret;
	}
}
