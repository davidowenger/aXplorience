package z.a;

import android.app.Activity;
import android.os.Bundle;


public class TApp extends Activity
{
	public TWrapper w;
	public long n;

	// Called when the activity is first created
	protected void onCreate(Bundle savedInstanceState)
    {
    	super.onCreate(savedInstanceState);

        // Init
        w = new TWrapper();
        w.activity = this;
        w.tFrame = new TAndroid(w);

        w.tFrame.tInit();
    }

    protected void onPause()
    {
        // Call user onPause event
    	super.onPause();
    }

    protected void onResume()
    {
        // Call user onResume event
    	super.onResume();
    }

	protected void onDestroy()
    {
		w.tFrame.tDestroy();
		super.onDestroy();
    }
}
