package z.a;

import android.content.Context;
import android.content.SharedPreferences;
import android.content.pm.ApplicationInfo;

public class TConfig
{
	public TWrapper w;
	public ApplicationInfo mAppInfo;
	public SharedPreferences mConfig;
	public SharedPreferences.Editor mEditor;

	public TConfig(TWrapper w)
	{
		this.w = w;
		mAppInfo = w.context.getApplicationInfo();
		mConfig = w.context.getSharedPreferences("settings", Context.MODE_PRIVATE);
		mEditor = mConfig.edit();
	}

	public void init()
	{
		w.dbh.get("Drop").delete("yes");

		w.aBOSeed = w.boSeed.getSeeds();
		w.aBODrop = w.boSeed.getDrops();

		if (w.aBOSeed.size() == 0) {
			w.aBOSeed.add(w.boSeed.addSeed("1", "Peer", "Hello world!"));
		}
	}

	public String gets(int key)
	{
		return mConfig.getString("" + key, "");
	}

	public int geti(int key)
	{
		return mConfig.getInt("" + key, -1);
	}

	public boolean getb(int key)
	{
		return mConfig.getBoolean("" + key, false);
	}

	public void sets(int key, String value)
	{
		mEditor.putString("" + key, value);
		mEditor.commit();
	}

	public void seti(int key, int value)
	{
		mEditor.putInt("" + key, value);
		mEditor.commit();
	}

	public void setb(int key, boolean value)
	{
		mEditor.putBoolean("" + key, value);
		mEditor.commit();
	}
}
