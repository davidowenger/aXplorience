package z.a;

import java.util.ArrayList;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.Gravity;
import android.view.View;
import android.widget.LinearLayout;
import android.widget.TextView;

public class TAppEdit extends Activity
{
	public TWrapper w;
	public BO_Drop mBODrop;
	public DBObject mDBDrop;
	public boolean mAlive;

	// Called when the activity is first created
	protected void onCreate(Bundle savedInstanceState)
    {
    	super.onCreate(savedInstanceState);

		mAlive = true;
    	w = new TWrapper();
        w.context = getApplication();
	    w.intent = getIntent();
    	w.dbh = new DBHandler(w);
    	w.boSeed = new BO_Seed(w);
    	
    	mBODrop = w.boSeed.getDrop(w.intent.getStringExtra(TApp.EXTRA_ID));
    	mDBDrop = mBODrop.mDBObject;
    	
		LinearLayout container = new LinearLayout(this);
		container.setOrientation(LinearLayout.HORIZONTAL);
		container.setGravity(Gravity.RIGHT);
		container.setPadding(5,5,5,5);
		container.setBackgroundColor(0xFFFFFFFF);

		LinearLayout left = new LinearLayout(this);
		left.setOrientation(LinearLayout.VERTICAL);
		left.setPadding(5,5,5,5);

		TextView text1 = new TextView(this);
		text1.setTextSize(20);
		text1.setGravity(Gravity.LEFT);
		text1.setText(mDBDrop.get("text"));

		left.addView(text1);
		container.addView(left);
		setContentView((View)container);
    }
}

class TAppEditListener implements View.OnClickListener
{
	public TWrapper w;
	public ArrayList<TWidgetMessage> maMessage; 

	TAppEditListener(TWrapper w)
	{
		this.w = w;
	}

    public void onClick(View view)
    {
		Intent intent = new Intent(w.tApp, TAppEdit.class);
        intent.putExtra(TApp.EXTRA_ID, w.aMessageSelected.get(0).mDBDrop.get("id"));
        w.tApp.startActivity(intent);
    }
}
