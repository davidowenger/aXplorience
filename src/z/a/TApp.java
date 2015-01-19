package z.a;

import android.app.ActionBar;
import android.app.Activity;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.content.Intent;
import android.content.res.Configuration;
import android.content.res.Resources;
import android.graphics.drawable.ColorDrawable;
import android.graphics.drawable.Drawable;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.support.v4.widget.DrawerLayout;
import android.support.v7.app.ActionBarDrawerToggle;
import android.view.Gravity;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.FrameLayout;
import android.widget.LinearLayout;
import android.widget.ListView;
import android.widget.ToggleButton;

public class TApp extends Activity
{
    public final static String EXTRA_ID = "z.a.ID";
    public final static String EXTRA_MESSAGE = "z.a.MESSAGE";
    public final static String EXTRA_CATEGORY = "z.a.CATEGORY";

    public final static int VIEW_HOME = 0;
    public final static int VIEW_SETTINGS = 1;
    public final static int VIEW_ABOUT = 2;
    public final static int VIEW_DETAILS = 3;
    public final static int VIEW_EDIT = 4;
    public final static int VIEW_ADD = 5;

	public TWrapper w;
	public int mIndex;
	public String mDBObjectId;
	public boolean mDrawerState;
	public float mDensity;
    public int mTextSize;
	public String[] maCategory;
	public boolean[] maCategorySelected;
	public boolean mIsAllChecked;
	public DBObject mDBObject;

	public int[] maColor;
	public int[] maColorBase;
	public String mInText;
	public String mOutText;

	public Resources mResources;
	public Drawable[] maDrawable;

    public DrawerLayout mAppHome;
    public LinearLayout mLinearLayout;
    public FrameLayout mFrameLayoutLeft;
    public FrameLayout mFrameLayoutRight;
    public ListView mListView;

	public LinearLayout mAppSettings;
	public LinearLayout mAppAbout;

	public ActionBar mActionBar;
    public ActionBarDrawerToggle mActionBarDrawerToggle;

	public ToggleButton mButtonAll;
	public TButtonAllListener mButtonAllListener;
	public Button mButtonEdit;
	public TButtonEditListener mButtonEditListener;
	public Button mButtonDelete;
	public TButtonDeleteListener mButtonDeleteListener;
	public Button mButtonAdd;
	public TButtonAddListener mButtonAddListener;

	public Configuration mConfiguration;
	public FragmentManager mFragmentManager;
	public FragmentTransaction mFragmentTransaction;
	public TFragmentHome mTFragmentHome;
	public TFragmentSettings mTFragmentSettings;
	public TFragmentAbout mTFragmentAbout;
    public TFragmentDrop mTFragmentDropDetails;
    public TFragmentDrop mTFragmentDropEdit;
    public TFragmentDrop mTFragmentDropADD;

	public String[] maMenu;
	public String[] maMenuItem;

    @Override
	protected void onCreate(Bundle vBundle)
    {
    	super.onCreate(vBundle);
        initContext();
        restore(vBundle);
        initResources();
        save(vBundle);
    }

    @Override
	protected void onRestart()
    {
    	super.onRestart();
    }

    @Override
	protected void onStart()
    {
        // This will call fragments' onActivityCreated
        // This will call fragments' onViewStateRestored
        // This will call fragments' onStart
    	super.onStart();
    }

    @Override
    protected void onRestoreInstanceState(Bundle vBundle)
    {
        super.onRestoreInstanceState(vBundle);
    }

    @Override
    protected void onResume()
    {
    	super.onResume();
        setView(mIndex, mDBObjectId);
    }

    @Override
    protected void onPause()
    {
        // This will call fragments' onPause
    	super.onPause();
    }

    @Override
    protected void onSaveInstanceState(Bundle vBundle)
    {
        save(vBundle);
        // This will call fragments' onSaveInstanceState
        super.onSaveInstanceState(vBundle);
    }

    @Override
    protected void onStop()
    {
        // This will call fragments' onStop
    	super.onStop();
    }

    @Override
	protected void onDestroy()
    {
		w.tFrame.tDestroy();
        // This will call fragments' onDestroy
        // This will call fragments' onDestroyView
        // This will call fragments' onDetach
		super.onDestroy();
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu)
    {
        menu.removeItem(TWrapper.ITEM_ADD);
        menu.removeItem(TWrapper.ITEM_EDIT);
        menu.removeItem(TWrapper.ITEM_DELETE);
        menu.removeItem(TWrapper.ITEM_SAVE);
        return super.onCreateOptionsMenu(menu);
    }

    public boolean onOptionsItemSelected(MenuItem item)
    {
        return setView(item.getItemId(), "") || mActionBarDrawerToggle.onOptionsItemSelected(item) || super.onOptionsItemSelected(item);
    }

	public void addDropIn(ViewGroup vViewGroup, BO_Drop drop)
	{
		if (drop.mDBObject.get("archived").equals(w.dbh.FALSE)) {
			TWidgetMessage widget = new TWidgetInboundMessage(w, drop);
			vViewGroup.addView(widget);
			w.aMessage.add(widget);

			// if all then setChecked(true)
		}
        //System.out.println("Adding to view: " + vViewGroup.getId());
	}

	public void addDropOut(ViewGroup vViewGroup, BO_Drop drop)
	{
		if (drop.mDBObject.get("archived").equals(w.dbh.FALSE)) {
			TWidgetMessage widget = new TWidgetOutboundMessage(w, drop);
			vViewGroup.addView(widget);
			w.aMessage.add(widget);

			// if all then setChecked(true)
		}
        //System.out.println("Adding to view: " + vViewGroup.getId());
	}

    public void initContext()
    {
        mDBObject = null;
        mIndex = VIEW_HOME;
        mIsAllChecked = false;
        mResources = getResources();
        mDensity = mResources.getDisplayMetrics().density;
        mTextSize = (int)(14*mDensity);
        maColorBase = new int[] {
            0xFFFFE4E4, //red 1
            0xFFFFCACA, //red 2
            0xFFCC0000, //red
            0xFFF0F8DB, //green 1
            0xFFE2F0B6, //green 2
            0xFF669900, //green
            0xFFE2F4FB, //blue 1
            0xFFC5EAF8, //blue 2
            0xFF0099CC, //blue
            0xFFFFF6DF, //yellow 1
            0xFFFFECC0, //yellow 2
            0xFFFF8A00, //yellow
            0xFFF5EAFA, //purple 1
            0xFFE5CAF2, //purple 2
            0xFF9933CC, //purple
            0xFFFFFFFF, //white
            0xFFE8E8E8, //grey
            0xFF000000, //black
            0x00FFFFFF, //transparent
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
        maDrawable = new Drawable[] {
            mResources.getDrawable(R.drawable.ic_visibility_grey),
            mResources.getDrawable(R.drawable.ic_visibility_green),
            mResources.getDrawable(R.drawable.ic_visibility_black_48dp),
            mResources.getDrawable(R.drawable.ic_left_black),
            mResources.getDrawable(R.drawable.ic_left_green),
            mResources.getDrawable(R.drawable.ic_right_black),
            mResources.getDrawable(R.drawable.ic_right_green),
            mResources.getDrawable(R.drawable.ic_action_edit),
            mResources.getDrawable(R.drawable.ic_action_delete),
            mResources.getDrawable(R.drawable.ic_action_save),
            mResources.getDrawable(R.drawable.ic_action_add),
        };
        maMenu = new String[] {
                "Home",
                "Settings",
                "About"
        };
        maCategory = new String[] {
            "Listen to Music",
            "Have a Drink",
            "Play some Game",
            "See some Event"
        };
        maCategorySelected = new boolean[] {
            true,
            true,
            true,
            true
        };
    }

	public void initResources()
	{
        // Init worker threads
        w = new TWrapper();
        w.tApp = this;
        w.tFrame = new TAndroid(w);
        w.tFrame.tInit();

		mConfiguration = mResources.getConfiguration();
    	mAppHome = new DrawerLayout(this);
        mLinearLayout = new LinearLayout(this);
        mFrameLayoutLeft = new FrameLayout(this);
        mFrameLayoutRight = new FrameLayout(this);
    	mListView = new ListView(this);
		mActionBar = getActionBar();

    	mAppHome.setId(1234);
    	mAppHome.setLayoutParams(new DrawerLayout.LayoutParams(DrawerLayout.LayoutParams.MATCH_PARENT, DrawerLayout.LayoutParams.MATCH_PARENT, Gravity.LEFT));

        mLinearLayout.setId(12345);
        mLinearLayout.setGravity(Gravity.LEFT);
        mLinearLayout.setOrientation(LinearLayout.HORIZONTAL);
        mLinearLayout.setLayoutParams(new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.MATCH_PARENT));

        mFrameLayoutLeft.setId(0x1111);
        mFrameLayoutLeft.setLayoutParams(new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.MATCH_PARENT));
        mFrameLayoutLeft.setVisibility(View.GONE);

        mFrameLayoutRight.setId(0x2222);
        mFrameLayoutRight.setLayoutParams(new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.MATCH_PARENT));
        mFrameLayoutRight.setVisibility(View.VISIBLE);

        if (mConfiguration.screenWidthDp >= 480) {
            mFrameLayoutLeft.setLayoutParams(new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.MATCH_PARENT, 1));
            mFrameLayoutLeft.setVisibility(View.VISIBLE);

            mFrameLayoutRight.setLayoutParams(new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.MATCH_PARENT, 1));
            mFrameLayoutRight.setVisibility(View.VISIBLE);
        }
    	mListView.setId(123456);
    	mListView.setLayoutParams(new DrawerLayout.LayoutParams((int)(240*mDensity), DrawerLayout.LayoutParams.MATCH_PARENT, Gravity.LEFT));
    	mListView.setChoiceMode(ListView.CHOICE_MODE_SINGLE);
    	mListView.setDivider(new ColorDrawable(0x00000000));
    	mListView.setDividerHeight(0);
    	mListView.setBackground(new ColorDrawable(0xFFFFFFFF));

    	mListView.setAdapter(new ArrayAdapter<String>(this, R.layout.drawer_items, maMenu));
    	mListView.setOnItemClickListener(new TDrawerItemClickListener(w));

		mActionBar.setIcon(R.drawable.ic_launcher);
		mActionBar.setDisplayHomeAsUpEnabled(true);
		mActionBar.setHomeButtonEnabled(true);

        mLinearLayout.addView(mFrameLayoutLeft);
        mLinearLayout.addView(mFrameLayoutRight);
    	mAppHome.addView(mLinearLayout);
    	mAppHome.addView(mListView);

    	mActionBarDrawerToggle = new TActionBarDrawer(w, mAppHome, R.string.drawer_open, R.string.drawer_close);
        mActionBarDrawerToggle.setDrawerIndicatorEnabled(false);
        mAppHome.setDrawerListener(mActionBarDrawerToggle);

        mTFragmentHome = new TFragmentHome();
        mTFragmentSettings = new TFragmentSettings();
        mTFragmentAbout = new TFragmentAbout();
        mFragmentManager = getFragmentManager();

        setContentView(mAppHome);
	}

    public ViewGroup getContentView()
    {
        ViewGroup vViewGroup = null;

        try {
            if (mConfiguration.screenWidthDp >= 480) {
                vViewGroup = (ViewGroup)(mFrameLayoutLeft.getChildAt(0));
            } else {
                vViewGroup = (ViewGroup)(mFrameLayoutRight.getChildAt(0));
            }
            vViewGroup = (ViewGroup)((ViewGroup)vViewGroup.getChildAt(1)).getChildAt(0);
        } catch (Exception e) {
            vViewGroup = null;
            //System.out.println("View path has been destroyed and could not be found this time.");
        }
        return vViewGroup;
    }

	public void populate(ViewGroup vViewGroup)
	{
	    if (vViewGroup != null) {
            //System.out.println("clearing: " + vViewGroup.getId());
            vViewGroup.removeAllViews();

            w.aBOSeed = w.boSeed.getSeeds();
            w.aBODrop = w.boSeed.getDrops();
            //System.out.println("Fetched messages: " + (w.aBOSeed.size() + w.aBODrop.size()));

    		for (BO_Drop seed : w.aBOSeed) {
    			addDropOut(vViewGroup, seed);
    		}
    		for (BO_Drop drop : w.aBODrop) {
    			addDropIn(vViewGroup, drop);
    		}
	    }
	}

	public void setAllState()
	{
		for (TWidgetMessage vTWidgetMessage : w.aMessage) {
			vTWidgetMessage.setState();
		}
	}

	public void setAllState(boolean vChecked)
	{
		for (TWidgetMessage vTWidgetMessage : w.aMessage) {
			vTWidgetMessage.setState(vChecked);
		}
	}

	public void setState()
	{
	}

	public boolean setView(int vIndex, String vDBObjectId)
	{
		boolean ret = true;

        if (vIndex < w.tApp.maMenu.length) {
            w.tApp.mListView.setItemChecked(vIndex, true);
        } else {
            w.tApp.mListView.setItemChecked(0, true);
        }
	    switch (vIndex) {
    	case android.R.id.home:
            //System.out.println("android.R.id.home");
            //System.out.println("android.R.id.home");
            //System.out.println("android.R.id.home");
    	    ret = mFragmentManager.popBackStackImmediate(); // || setView(VIEW_HOME, "");
            break;
        case VIEW_HOME:
            //System.out.println("VIEW_HOME");
            //System.out.println("VIEW_HOME");
            //System.out.println("VIEW_HOME");
            while (mFragmentManager.popBackStackImmediate()) {
                // NOP
            }
            if (mConfiguration.screenWidthDp >= 480) {
                mTFragmentAbout = new TFragmentAbout();

                mFragmentTransaction = mFragmentManager.beginTransaction();
                mFragmentTransaction.replace(mFrameLayoutLeft.getId(), mTFragmentHome);
                mFragmentTransaction.commit();

                mFragmentTransaction = mFragmentManager.beginTransaction();
                mFragmentTransaction.replace(mFrameLayoutRight.getId(), mTFragmentAbout);
                mFragmentTransaction.commit();
    	    } else {
                mFragmentTransaction = mFragmentManager.beginTransaction();
                mFragmentTransaction.replace(mFrameLayoutRight.getId(), mTFragmentHome);
                mFragmentTransaction.commit();
    	    }
            mIndex = vIndex;
            break;
        case VIEW_SETTINGS:
            //System.out.println("VIEW_SETTINGS");
            //System.out.println("VIEW_SETTINGS");
            //System.out.println("VIEW_SETTINGS");
            mTFragmentSettings = new TFragmentSettings();

            while (mFragmentManager.popBackStackImmediate()) {
                // NOP
            }
            if (mConfiguration.screenWidthDp >= 480) {
                mFragmentTransaction = mFragmentManager.beginTransaction();
                mFragmentTransaction.replace(mFrameLayoutLeft.getId(), mTFragmentHome);
                mFragmentTransaction.commit();

                mFragmentTransaction = mFragmentManager.beginTransaction();
                mFragmentTransaction.replace(mFrameLayoutRight.getId(), mTFragmentSettings);
                mFragmentTransaction.commit();
    	    } else {
                mFragmentTransaction = mFragmentManager.beginTransaction();
                mFragmentTransaction.replace(mFrameLayoutRight.getId(), mTFragmentHome);
                mFragmentTransaction.commit();

                mFragmentTransaction = mFragmentManager.beginTransaction();
                mFragmentTransaction.replace(mFrameLayoutRight.getId(), mTFragmentSettings);
                mFragmentTransaction.addToBackStack(null);
                mFragmentTransaction.commit();
    	    }
            //mListView.setItemChecked(VIEW_SETTINGS, true);
            mIndex = vIndex;
            break;
        case VIEW_ABOUT:
            //System.out.println("VIEW_ABOUT");
            //System.out.println("VIEW_ABOUT");
            //System.out.println("VIEW_ABOUT");
            mTFragmentAbout = new TFragmentAbout();

            while (mFragmentManager.popBackStackImmediate()) {
                // NOP
            }
            if (mConfiguration.screenWidthDp >= 480) {
                mFragmentTransaction = mFragmentManager.beginTransaction();
                mFragmentTransaction.replace(mFrameLayoutLeft.getId(), mTFragmentHome);
                mFragmentTransaction.commit();

                mFragmentTransaction = mFragmentManager.beginTransaction();
                mFragmentTransaction.replace(mFrameLayoutRight.getId(), mTFragmentAbout);
                mFragmentTransaction.commit();
    	    } else {
                mFragmentTransaction = mFragmentManager.beginTransaction();
                mFragmentTransaction.replace(mFrameLayoutRight.getId(), mTFragmentHome);
                mFragmentTransaction.commit();

                mFragmentTransaction = mFragmentManager.beginTransaction();
                mFragmentTransaction.replace(mFrameLayoutRight.getId(), mTFragmentAbout);
                mFragmentTransaction.addToBackStack(null);
                mFragmentTransaction.commit();
    	    }
            // mListView.setItemChecked(VIEW_ABOUT, true);
            mIndex = vIndex;
            break;
        case VIEW_DETAILS:
            //System.out.println("VIEW_DETAILS");
            //System.out.println("VIEW_DETAILS");
            //System.out.println("VIEW_DETAILS");
            mDBObjectId = vDBObjectId;
            mDBObject = w.dbh.get("Drop").getInstance(mDBObjectId);

            if (!mDBObject.get("id").equals("")) {
                mTFragmentDropDetails = new TFragmentDrop();
                mTFragmentDropDetails.init(VIEW_DETAILS, mDBObjectId);

                while (mFragmentManager.popBackStackImmediate()) {
                    // NOP
                }
                if (mConfiguration.screenWidthDp >= 480) {
                    mFragmentTransaction = mFragmentManager.beginTransaction();
                    mFragmentTransaction.replace(mFrameLayoutLeft.getId(), mTFragmentHome);
                    mFragmentTransaction.commit();

                    mFragmentTransaction = mFragmentManager.beginTransaction();
                    mFragmentTransaction.replace(mFrameLayoutRight.getId(), mTFragmentDropDetails);
                    mFragmentTransaction.commit();
                } else {
                    mFragmentTransaction = mFragmentManager.beginTransaction();
                    mFragmentTransaction.replace(mFrameLayoutRight.getId(), mTFragmentHome);
                    mFragmentTransaction.commit();

                    mFragmentTransaction = mFragmentManager.beginTransaction();
                    mFragmentTransaction.replace(mFrameLayoutRight.getId(), mTFragmentDropDetails);
                    mFragmentTransaction.addToBackStack(null);
                    mFragmentTransaction.commit();
                }
                // mListView.setItemChecked(VIEW_HOME, true);
                mIndex = vIndex;
            } else {
                setView(VIEW_HOME, "");
            }
            break;
        case VIEW_EDIT:
            //System.out.println("VIEW_EDIT");
            //System.out.println("VIEW_EDIT");
            //System.out.println("VIEW_EDIT");
            mDBObjectId = vDBObjectId;
            mDBObject = w.dbh.get("Drop").getInstance(mDBObjectId);

            while (mFragmentManager.popBackStackImmediate()) {
                // NOP
            }
            if (!mDBObject.get("id").equals("")) {
                mTFragmentDropDetails = new TFragmentDrop();
                mTFragmentDropDetails.init(VIEW_DETAILS, mDBObjectId);

                mTFragmentDropEdit = new TFragmentDrop();
                mTFragmentDropEdit.init(VIEW_EDIT, mDBObjectId);

                if (mConfiguration.screenWidthDp >= 480) {
                    mFragmentTransaction = mFragmentManager.beginTransaction();
                    mFragmentTransaction.replace(mFrameLayoutLeft.getId(), mTFragmentHome);
                    mFragmentTransaction.commit();

                    mFragmentTransaction = mFragmentManager.beginTransaction();
                    mFragmentTransaction.replace(mFrameLayoutRight.getId(), mTFragmentDropDetails);
                    mFragmentTransaction.commit();

                    mFragmentTransaction = mFragmentManager.beginTransaction();
                    mFragmentTransaction.replace(mFrameLayoutRight.getId(), mTFragmentDropEdit);
                    mFragmentTransaction.addToBackStack(null);
                    mFragmentTransaction.commit();
                } else {
                    mFragmentTransaction = mFragmentManager.beginTransaction();
                    mFragmentTransaction.replace(mFrameLayoutRight.getId(), mTFragmentHome);
                    mFragmentTransaction.commit();

                    mFragmentTransaction = mFragmentManager.beginTransaction();
                    mFragmentTransaction.replace(mFrameLayoutRight.getId(), mTFragmentDropDetails);
                    mFragmentTransaction.addToBackStack(null);
                    mFragmentTransaction.commit();

                    mFragmentTransaction = mFragmentManager.beginTransaction();
                    mFragmentTransaction.replace(mFrameLayoutRight.getId(), mTFragmentDropEdit);
                    mFragmentTransaction.addToBackStack(null);
                    mFragmentTransaction.commit();
                }
                //mListView.setItemChecked(VIEW_HOME, true);
                mIndex = vIndex;
            } else {
                setView(VIEW_HOME, "");
            }
            break;
        case VIEW_ADD:
            //System.out.println("VIEW_ADD");
            //System.out.println("VIEW_ADD");
            //System.out.println("VIEW_ADD");
            mDBObjectId = vDBObjectId;
            mTFragmentDropADD = new TFragmentDrop();
            mTFragmentDropADD.init(VIEW_ADD, "");

            while (mFragmentManager.popBackStackImmediate()) {
                // NOP
            }
            if (mConfiguration.screenWidthDp >= 480) {
                mFragmentTransaction = mFragmentManager.beginTransaction();
                mFragmentTransaction.replace(mFrameLayoutLeft.getId(), mTFragmentHome);
                mFragmentTransaction.commit();

                mFragmentTransaction = mFragmentManager.beginTransaction();
                mFragmentTransaction.replace(mFrameLayoutRight.getId(), mTFragmentDropADD);
                mFragmentTransaction.commit();
            } else {
                mFragmentTransaction = mFragmentManager.beginTransaction();
                mFragmentTransaction.replace(mFrameLayoutRight.getId(), mTFragmentHome);
                mFragmentTransaction.commit();

                mFragmentTransaction = mFragmentManager.beginTransaction();
                mFragmentTransaction.replace(mFrameLayoutRight.getId(), mTFragmentDropADD);
                mFragmentTransaction.addToBackStack(null);
                mFragmentTransaction.commit();
            }
            //mListView.setItemChecked(VIEW_HOME, true);
            mIndex = vIndex;
            break;
        default:
        	ret = false;
            break;
	    }
	    return ret;
    }

    public void restore(Bundle vBundle)
    {
        if (vBundle != null) {
            mIndex = vBundle.getInt("mIndex");
            mDBObjectId = vBundle.getString("mDBObjectId");
        }
    }

    public void save(Bundle vBundle)
    {
        if (vBundle != null) {
            vBundle.putInt("mIndex", mIndex);
            vBundle.putString("mDBObjectId", mDBObjectId);
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
			w.tApp.addDropIn(w.tApp.getContentView(), (BO_Drop)m.obj);
			break;
		case DROP_OUT:
		    w.tApp.addDropOut(w.tApp.getContentView(), (BO_Drop)m.obj);
			break;
		case DROP_POPULATE:
		    w.tApp.populate(w.tApp.getContentView());
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
		w.tApp.mIsAllChecked = !w.tApp.mIsAllChecked;
		w.aMessageSelected.clear();
		w.tApp.setAllState(w.tApp.mIsAllChecked);
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

class TActionBarDrawer extends ActionBarDrawerToggle
{
	public TWrapper w;

	public TActionBarDrawer(TWrapper w, DrawerLayout sDrawerLayout, int srOpen, int srClose)
	{
		super(w.tApp, sDrawerLayout, srOpen, srClose);
		this.w = w;
	}

    public void onDrawerOpened(View drawerView)
    {
    	w.tApp.invalidateOptionsMenu();
    	w.tApp.mDrawerState = true;
    	super.onDrawerOpened(drawerView);
    }

    public void onDrawerClosed(View drawerView)
    {
        w.tApp.invalidateOptionsMenu();
    	w.tApp.mDrawerState = false;
    	super.onDrawerClosed(drawerView);
    }
};

class TDrawerItemClickListener implements ListView.OnItemClickListener
{
	public TWrapper w;

	public TDrawerItemClickListener(TWrapper w)
	{
		super();
		this.w = w;
	}

    @Override
    public void onItemClick(AdapterView<?> parent, View view, int vIndex, long id)
    {
        w.tApp.mAppHome.closeDrawer(w.tApp.mListView);
        w.tApp.setView(vIndex, "");
        w.tApp.mFrameLayoutRight.invalidate();w.tApp.mActionBarDrawerToggle.syncState();
    }
}
