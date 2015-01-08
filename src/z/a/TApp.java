package z.a;

import java.text.DateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Map;

import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.Gravity;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup.LayoutParams;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.ScrollView;
import android.widget.SimpleExpandableListAdapter;
import android.widget.TextView;
import android.support.v7.app.ActionBar;
import android.support.v7.app.ActionBarActivity;


public class TApp extends ActionBarActivity
{
	public TWrapper w;
	public String[] maCategory;
	public String mInText;
	public String mOutText;
	public ScrollView mHome;
	public LinearLayout mHomeContainer;
	public LinearLayout[] maCategoryView;
	public LinearLayout mSettings;
	public LinearLayout mAbout;
	public ArrayList<TextView> maText;
	//public SimpleExpandableListAdapter mExpandableListView;
	//public ArrayList<Map<String, Object>> mGroupData;
	
	// Called when the activity is first created
	protected void onCreate(Bundle savedInstanceState)
    {
    	super.onCreate(savedInstanceState);

		int i;
		
        maText = new ArrayList<TextView>();
		//mGroupData = new ArrayList<Map<String, Object>>();
		mInText = "IN";
		mOutText = "OUT";
		maCategory = new String[] {
			"listen to music",
			"have a drink",
			"play some game",
			"see some event"
		};
		maCategoryView = new LinearLayout[maCategory.length];

        // Init
        w = new TWrapper();
        w.tApp = this;
        w.tFrame = new TAndroid(w);
		w.tFrame.tInit();

		mHome = new ScrollView(this);
		mHomeContainer = new LinearLayout(this);
		mSettings = new LinearLayout(this);
		mAbout = new LinearLayout(this);

		mHomeContainer.setOrientation(LinearLayout.VERTICAL);
		mSettings.setOrientation(LinearLayout.VERTICAL);
		mAbout.setOrientation(LinearLayout.VERTICAL);

		mHome.setPadding(5,5,5,5);
		mHomeContainer.setPadding(5,5,5,5);
		mSettings.setPadding(5,5,5,5);
		mAbout.setPadding(5,5,5,5);

		for ( i = 0 ; i < maCategoryView.length ; ++i ) {
			TextView title = new TextView(this);
			title.setTextSize(20);
			title.setGravity(Gravity.LEFT);
			title.setPadding(5,5,5,5);
			title.setBackgroundColor(0xFF9BAF6E); //0xEBECEC
			title.setText(maCategory[i]);
			maCategoryView[i] = new LinearLayout(this);
			maCategoryView[i].setOrientation(LinearLayout.VERTICAL);
			maCategoryView[i].setPadding(5,5,5,5);
			maCategoryView[i].addView(title);
			mHomeContainer.addView(maCategoryView[i]);
		}
		mHome.addView(mHomeContainer);
		setContentView((View)mHome);

        Date now = new Date();
        String timestamp = "" + now.getTime();
        addText("0", timestamp, "test 1");
        addText("0", timestamp, "test 2");
        addText("1", timestamp, "test 3");

		TextView settings = new TextView(this);
		settings.setTextSize(20);
		settings.setGravity(Gravity.LEFT);
		settings.setText("Be sure to enable Bluetooth. Use discoverability for your phone to be seen.");
		mSettings.addView(settings);

		TextView about = new TextView(this);
		about.setTextSize(20);
		about.setGravity(Gravity.LEFT);
		about.setText("v0.1 Beta");
		mAbout.addView(about);
    }

	public void addText(String id_cat,String date,String text)
	{
		LinearLayout container = new LinearLayout(this);
		container.setOrientation(LinearLayout.HORIZONTAL);
		container.setGravity(Gravity.RIGHT);
		container.setPadding(5,5,5,5);
		container.setBackgroundColor(0xFFFFFFFF);

		LinearLayout left = new LinearLayout(this);
		left.setOrientation(LinearLayout.VERTICAL);
		left.setPadding(5,5,5,5);

		LinearLayout right = new LinearLayout(this);
		right.setOrientation(LinearLayout.VERTICAL);
		right.setPadding(5,5,5,5);

		TextView text1 = new TextView(this);
		text1.setTextSize(20);
		text1.setGravity(Gravity.LEFT);
		text1.setText(
			mInText +
			"  " +
			DateFormat.getTimeInstance().format(new Date(Long.parseLong(date)))
		);

		TextView text2 = new TextView(this);
		text2.setTextSize(20);
		text2.setGravity(Gravity.LEFT);
		text2.setText(
			text
		);
		
		final Button button1 = new Button(this);
		final Intent intent = new Intent(this, TAppEdit.class);
		
		button1.setTextSize(20);
		text2.setGravity(Gravity.LEFT);
		button1.setBackgroundColor(0xFFFFFFFF);
		button1.setText("DELETE");
		button1.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
            	startActivity(intent);
            }
        });

		left.addView(text1);
		left.addView(text2);
		right.addView(button1);
		container.addView(left);
		container.addView(right);
		maCategoryView[Integer.parseInt(id_cat)].addView(container);
	}
	
	public boolean onCreateOptionsMenu(Menu menu)
    {
		ActionBar actionBar = getSupportActionBar();
		actionBar.setTitle("aXplorience");
		actionBar.setDisplayOptions(ActionBar.DISPLAY_SHOW_HOME|ActionBar.DISPLAY_SHOW_TITLE|ActionBar.DISPLAY_USE_LOGO);

        MenuItem layout = menu.add(Menu.NONE, 1, 1, "Home");
        layout.setShowAsAction(MenuItem.SHOW_AS_ACTION_IF_ROOM|MenuItem.SHOW_AS_ACTION_WITH_TEXT);

        MenuItem settings = menu.add(Menu.NONE, 2, 2, "Settings");
        settings.setShowAsAction(MenuItem.SHOW_AS_ACTION_IF_ROOM|MenuItem.SHOW_AS_ACTION_WITH_TEXT);
        
        MenuItem about = menu.add(Menu.NONE, 3, 3, "About");
        about.setShowAsAction(MenuItem.SHOW_AS_ACTION_IF_ROOM|MenuItem.SHOW_AS_ACTION_WITH_TEXT);

        return super.onCreateOptionsMenu(menu);
    }
	
	public boolean onOptionsItemSelected(MenuItem item)
    {
		boolean ret = true;
		
	    // Handle presses on the action bar items
	    switch (item.getItemId()) {
	        case 1:
	        	setContentView((View)mHome);
	            break;
	        case 2:
	        	setContentView((View)mSettings);
	            break;
	        case 3:
	        	setContentView((View)mAbout);
	            break;
	        default:
	        	ret = super.onOptionsItemSelected(item);
	            break;
	    }
	    return ret;
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

class TAppEdit extends ActionBarActivity
{
	public TWrapper w;
	
	// Called when the activity is first created
	protected void onCreate(Bundle savedInstanceState)
    {
    	super.onCreate(savedInstanceState);
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
			w.tApp.addText(drop.mDBObject.get("id_cat"),drop.mDBObject.get("date"), drop.mDBObject.get("text"));
			break;
		default:
			super.handleMessage(m);
			break;
		}
	}
}

//mExpandableListView = new SimpleExpandableListAdapter(
//		w.context
//		mGroupData, 
//		int expandedGroupLayout, 
//		int collapsedGroupLayout, 
//		String[] groupFrom, 
//		int[] groupTo, 
//		List<? extends List<? extends Map<String, ?>>> childData, 
//		int childLayout, 
//		String[] childFrom, 
//		int[] childTo
//);

