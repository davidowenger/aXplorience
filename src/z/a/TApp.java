package z.a;

import java.util.ArrayList;

import android.app.Activity;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup.LayoutParams;
import android.widget.LinearLayout;
import android.widget.TextView;


public class TApp extends Activity
{
	public TWrapper w;
	public LinearLayout mLayout;
	public ArrayList<TextView> maText;

	// Called when the activity is first created
	protected void onCreate(Bundle savedInstanceState)
    {
    	super.onCreate(savedInstanceState);
        maText = new ArrayList<TextView>();

        // Init
        w = new TWrapper();
        w.tApp = this;
        w.tFrame = new TAndroid(w);
		mLayout = new LinearLayout(this);

        w.tFrame.tInit();
		mLayout.setOrientation(LinearLayout.VERTICAL);
		mLayout.setLayoutParams(new LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.MATCH_PARENT));
		mLayout.setGravity(Gravity.CENTER);
		setContentView((View)mLayout);
    }

	public void addText(String str)
	{
		TextView text = new TextView(this);
		text.setTextSize(20);
		text.setGravity(Gravity.CENTER_HORIZONTAL);
		text.setTextSize(20);
		text.setText(str);
        maText.add(text);
		mLayout.addView(text);
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

class TAppHandler extends Handler
{
	public final int DROP_RECEIVED = 0;

	public TWrapper w;
	String mMessage;

	public TAppHandler(TWrapper w)
	{
		this.w = w;
		mMessage = "BEGIN:";
	}

	public void handleMessage(Message m)
	{
		switch (m.what) {
		case DROP_RECEIVED:
			BO_Drop drop = (BO_Drop)m.obj;
			w.tApp.addText(drop.mDBObject.get("text"));
			break;
		default:
			super.handleMessage(m);
			break;
		}
	}
}
