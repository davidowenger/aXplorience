package z.a;

import java.util.ArrayList;

import android.content.Intent;
import android.content.res.Resources;
import android.graphics.drawable.Drawable;
import android.graphics.drawable.StateListDrawable;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.Gravity;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.ScrollView;
import android.widget.TextView;
import android.widget.ToggleButton;
import android.support.v7.app.ActionBar;
import android.support.v7.app.ActionBarActivity;

public class TApp extends ActionBarActivity
{
    public final static String EXTRA_ID = "z.a.ID";
    public final static String EXTRA_MESSAGE = "z.a.MESSAGE";
    public final static String EXTRA_CATEGORY = "z.a.CATEGORY";

	public TWrapper w;
	public String[] maCategory;
	public int[] maColor;
	public String mInText;
	public String mOutText;
	public StateListDrawable mStateListDrawable;
	public Resources mResources;
	public Drawable[] maDrawable;
	public LinearLayout mHome;
	public LinearLayout mHomeBar;
	public ScrollView mHomeScroll;
	public LinearLayout mHomeContent;
	public LinearLayout mSettings;
	public LinearLayout mAbout;
	public ToggleButton mButtonAll;
	public TButtonAllListener mButtonAllListener;
	public Button mButtonEdit;
	public TButtonEditListener mButtonEditListener;
	public Button mButtonDelete;
	public TButtonDeleteListener mButtonDeleteListener;
	public Button mButtonAdd;
	public TButtonAddListener mButtonAddListener;
	public boolean mState;
	
	// Called when the activity is first created
	protected void onCreate(Bundle savedInstanceState)
    {
    	super.onCreate(savedInstanceState);

    	mState = false;
		mResources = getResources();
		maDrawable = new Drawable[] {
				mResources.getDrawable(R.drawable.ic_visibility_grey),
				mResources.getDrawable(R.drawable.ic_visibility_black_48dp),
				mResources.getDrawable(R.drawable.ic_visibility_green),
				mResources.getDrawable(R.drawable.ic_left_black),
				mResources.getDrawable(R.drawable.ic_left_green),
				mResources.getDrawable(R.drawable.ic_right_black),
				mResources.getDrawable(R.drawable.ic_right_green),
				mResources.getDrawable(R.drawable.ic_action_edit),
				mResources.getDrawable(R.drawable.ic_action_delete)
		};
		maColor = new int[] {
			0xFF0099CC,
			0xFF669900,
			0xFFCC0000,
			0xFFFF8A00,
			0xFF9933CC,
			0xFF99CC00, //green selected 
			0xFFFFFFFF, //blank line 
			0xFFE2F4FB, //line
			0xFFFFFFFF, //home bar
			0xFF000000,
			0xFFE8E8E8 //greyed text
		};
		maCategory = new String[] {
			"listen to music",
			"have a drink",
			"play some game",
			"see some event"
		};

        // Init
        w = new TWrapper();
        w.tApp = this;
        w.tFrame = new TAndroid(w);
		w.tFrame.tInit();

		mHome = new LinearLayout(this);
		mHomeBar = new LinearLayout(this);
		mHomeScroll = new ScrollView(this);
		mHomeContent = new LinearLayout(this);
		mSettings = new LinearLayout(this);
		mAbout = new LinearLayout(this);

		mHome.setOrientation(LinearLayout.VERTICAL);
		mHomeBar.setOrientation(LinearLayout.HORIZONTAL);
		mHomeContent.setOrientation(LinearLayout.VERTICAL);
		mSettings.setOrientation(LinearLayout.VERTICAL);
		mAbout.setOrientation(LinearLayout.VERTICAL);

		mHomeBar.setPadding(0,0,0,0);
		mHomeContent.setPadding(5,5,5,5);
		mSettings.setPadding(0,0,0,0);
		mAbout.setPadding(0,0,0,0);
		
		mHomeBar.setBackgroundColor(maColor[8]);
		
		mButtonAll = new ToggleButton(w.tApp);
		mButtonAllListener = new TButtonAllListener(w);

		mButtonAll.setLayoutParams(new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1));
		mButtonAll.setBackgroundColor(0x00000000);
		mButtonAll.setTextSize(20);
		mButtonAll.setGravity(Gravity.CENTER);
		mButtonAll.setText("All");
		mButtonAll.setTextOn("All");
		mButtonAll.setTextOff("All");
		mButtonAll.setOnClickListener(mButtonAllListener);

		mButtonEdit = new Button(w.tApp);
		mButtonEditListener = new TButtonEditListener(w);

		mButtonEdit.setLayoutParams(new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1));
		mButtonEdit.setBackgroundColor(0x00000000);
		mButtonEdit.setTextSize(20);
		mButtonEdit.setGravity(Gravity.CENTER);
		mButtonEdit.setText("Edit");
		mButtonEdit.setOnClickListener(mButtonEditListener);

		mButtonDelete = new Button(w.tApp);
		mButtonDeleteListener = new TButtonDeleteListener(w);

		mButtonDelete.setLayoutParams(new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1));
		mButtonDelete.setBackgroundColor(0x00000000);
		mButtonDelete.setTextSize(20);
		mButtonDelete.setGravity(Gravity.CENTER);
		mButtonDelete.setText("Del");
		mButtonDelete.setOnClickListener(mButtonDeleteListener);

		mButtonAdd = new Button(w.tApp);
		mButtonAddListener = new TButtonAddListener(w);

		mButtonAdd.setLayoutParams(new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1));
		mButtonAdd.setBackgroundColor(0x00000000);
		mButtonAdd.setTextSize(20);
		mButtonAdd.setGravity(Gravity.CENTER);
		mButtonAdd.setText("Add");
		mButtonAdd.setOnClickListener(mButtonAddListener);

		mHomeBar.addView(mButtonAll);
		mHomeBar.addView(mButtonEdit);
		mHomeBar.addView(mButtonDelete);
		mHomeBar.addView(mButtonAdd);

		mHomeScroll.addView(mHomeContent);

		mHome.addView(mHomeBar);
		mHome.addView(mHomeScroll);
		
		setState();
		setContentView(mHome);
		
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

	public void setState()
	{
		mState = false;
		mButtonAdd.setTextColor(maColor[9]);

		if (w.aMessageSelected.size() == 0) {
    		mButtonAll.setTextColor(maColor[9]);
			mButtonEdit.setTextColor(maColor[10]);
			mButtonDelete.setTextColor(maColor[10]);
		} else {
    		mButtonAll.setTextColor(maColor[9]);
			mButtonEdit.setTextColor(maColor[9]);
			mButtonDelete.setTextColor(maColor[9]);
	
			if (w.aMessageSelected.size() == w.aMessage.size()) {
	    		mButtonAll.setTextColor(maColor[5]);
	    		mState = true;
			}
		}
	}

	public void addDropIn(BO_Drop drop) 
	{
		TWidgetMessage widget = new TWidgetInboundMessage(w, drop);
		mHomeContent.addView(widget);
		w.aMessage.add(widget);
		
		// if all ...
	}

	public void addDropOut(BO_Drop drop) 
	{
		TWidgetMessage widget = new TWidgetOutboundMessage(w, drop);
		mHomeContent.addView(widget);
		w.aMessage.add(widget);
		
		// if all ...
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
	        	setContentView(mHome);
	            break;
	        case 2:
	        	setContentView(mSettings);
	            break;
	        case 3:
	        	setContentView(mAbout);
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

	public void populate()
	{
		for (BO_Drop seed : w.aBOSeed) {
			w.tApp.addDropOut(seed);
		}
		for (BO_Drop drop : w.aBODrop) {
			w.tApp.addDropIn(drop);
		}
	}
}

class TAppHandler extends Handler
{
	public final int DROP = 0;
	public final int DROP_IN = 1;
	public final int DROP_OUT = 2;
	public final int DROP_POPULATE = 3;

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
		case DROP_IN:
			w.tApp.addDropIn((BO_Drop)m.obj);
			break;
		case DROP_OUT:
			w.tApp.addDropOut((BO_Drop)m.obj);
			break;
		case DROP_POPULATE:
			w.tApp.populate();
			break;
		default:
			super.handleMessage(m);
			break;
		}
	}
}

class TButtonAllListener implements View.OnClickListener
{
	public TWrapper w;

	TButtonAllListener(TWrapper w)
	{
		this.w = w;
	}

    public void onClick(View view)
    {
		w.tApp.mState = !w.tApp.mState;
		w.aMessageSelected.clear();
		for (TWidgetMessage vTWidgetMessage : w.aMessage) {
			vTWidgetMessage.setState(w.tApp.mState);
		}
    	w.tApp.setState();
    }
}

class TButtonEditListener implements View.OnClickListener
{
	public TWrapper w;

	TButtonEditListener(TWrapper w)
	{
		this.w = w;
	}

    public void onClick(View view)
    {
    	if (w.aMessageSelected.size() > 0) {
    		Intent intent = new Intent(w.tApp, TAppEdit.class);
            intent.putExtra(TApp.EXTRA_ID, w.aMessageSelected.get(0).mDBDrop.get("id"));
            w.tApp.startActivity(intent);
    	}
    }
}

class TButtonDeleteListener implements View.OnClickListener
{
	public TWrapper w;

	TButtonDeleteListener(TWrapper w)
	{
		this.w = w;
	}

    public void onClick(View view)
    {
		for (TWidgetMessage vTWidgetMessage : w.aMessageSelected) {
			vTWidgetMessage.mDBDrop.set("archived", w.dbh.TRUE).commit();
			w.aMessage.remove(vTWidgetMessage);
			w.tApp.mHomeContent.removeView(vTWidgetMessage);
		}
		w.aMessageSelected.clear();
		w.tApp.setState();
    }
}

class TButtonAddListener implements View.OnClickListener
{
	public TWrapper w;

	TButtonAddListener(TWrapper w)
	{
		this.w = w;
	}

    public void onClick(View view)
    {
		Intent intent = new Intent(w.tApp, TAppEdit.class);
        intent.putExtra(TApp.EXTRA_ID, "");
        w.tApp.startActivity(intent);
    }
}
