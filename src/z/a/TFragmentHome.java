package z.a;

import android.app.Activity;
import android.app.Fragment;
import android.os.Bundle;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.FrameLayout;
import android.widget.LinearLayout;
import android.widget.ScrollView;
import android.widget.TextView;

public class TFragmentHome extends Fragment
{
	// setHasOptionsMenu() during onCreate() for onCreateOptionsMenu() and onOptionsItemSelected() to be called
	// registerForContextMenu() for onCreateContextMenu() onContextItemSelected().
	// API 13 void onViewCreated(View view, Bundle vBundle
	public TWrapper w;
	public TApp mTApp;
	public LinearLayout mTFragmentView;
	public LinearLayout mTFragmentViewBar;
	public ScrollView mTFragmentViewScroll;
    public LinearLayout mTFragmentViewContent;
    public TextView mTextView;

	public TFragmentHome()
	{
		super();
        mTApp = null;
		mTFragmentView = null;
	}

    @Override
    public void onAttach(Activity vActivity)
    {
        super.onAttach(vActivity);
        initContext((TApp)vActivity);
    }

    @Override
    public void onCreate(Bundle vBundle)
    {
        // Input from init() or from Bundle is now ok
        super.onCreate(vBundle);
        setHasOptionsMenu(true);
    }

    @Override
	public View onCreateView(LayoutInflater inflater, ViewGroup parentView, Bundle vBundle)
	{
        return mTFragmentView;
	}

    @Override
	public void onActivityCreated(Bundle vBundle)
	{
        // Members from Activity are now ok
        super.onActivityCreated(vBundle);
        initData(mTApp.w);
        restore(vBundle);
        initView();
        save(vBundle);
	}

    @Override
    public void onViewStateRestored(Bundle vBundle)
    {
        super.onViewStateRestored(vBundle);
    }

    @Override
	public void onStart()
	{
		super.onStart();
	}

    @Override
	public void onResume()
	{
		super.onResume();
        //System.out.println("populating fragment: " + this.getId());
        //System.out.println("view: " + mTFragmentViewContent.getId());
        w.tApp.populate(mTFragmentViewContent);
        //mTFragmentViewContent.invalidate();
	}

    @Override
	public void onPause()
	{
		super.onPause();
	}

    @Override
    public void onSaveInstanceState(Bundle vBundle)
    {
        save(vBundle);
        super.onSaveInstanceState(vBundle);
    }

    @Override
	public void onStop()
	{
		super.onStop();
	}

    @Override
	public void onDestroyView()
	{
		super.onDestroyView();
	}

    @Override
	public void onDestroy()
	{
		super.onDestroy();
	}

    @Override
	public void onDetach()
	{
		super.onDetach();
	}

    @Override
    public void onCreateOptionsMenu(Menu menu, MenuInflater inflater)
    {
        menu.removeItem(TWrapper.ITEM_ADD);
        menu.removeItem(TWrapper.ITEM_EDIT);
        menu.removeItem(TWrapper.ITEM_DELETE);
        menu.removeItem(TWrapper.ITEM_SAVE);

        if (w.tApp.mConfiguration.screenWidthDp < 480) {
            MenuItem vMenuItemAdd = menu.add(Menu.NONE, TWrapper.ITEM_ADD, 1, "Add");
            vMenuItemAdd.setIcon(w.tApp.maDrawable[10]);
            vMenuItemAdd.setShowAsAction(MenuItem.SHOW_AS_ACTION_IF_ROOM);
        }
        super.onCreateOptionsMenu(menu, inflater);
    }

    @Override
    public void onPrepareOptionsMenu(Menu menu)
    {
        super.onPrepareOptionsMenu(menu);
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item)
    {
        int id = item.getItemId();
        boolean ret = false;

        if (id == TWrapper.ITEM_ADD) {
            w.tApp.setView(TApp.VIEW_ADD, "");
            ret = true;
        }
        return ret || super.onOptionsItemSelected(item);
    }

    public void init()
    {
    }

    public void initContext(TApp vTApp)
    {
        mTApp = vTApp;
        mTFragmentView = new LinearLayout(mTApp);
        mTFragmentViewScroll = new ScrollView(mTApp);
        mTFragmentViewContent = new LinearLayout(mTApp);
        mTextView = new TextView(mTApp);

        mTFragmentViewScroll.addView(mTFragmentViewContent);
        mTFragmentView.addView(mTextView);
        mTFragmentView.addView(mTFragmentViewScroll);
    }

    public void initData(TWrapper w)
    {
        this.w = w;
    }

    public void initView()
    {
        //System.out.println("fragment: " + this.getId());

		int vPadding = (int)(5*w.tApp.mDensity);

        mTFragmentView.setId(0xFAE0);
        mTFragmentView.setOrientation(LinearLayout.VERTICAL);
        mTFragmentView.setLayoutParams(new FrameLayout.LayoutParams(FrameLayout.LayoutParams.MATCH_PARENT, FrameLayout.LayoutParams.MATCH_PARENT));

        mTFragmentViewContent.setId(0x12321);
        mTFragmentViewContent.setOrientation(LinearLayout.VERTICAL);
        mTFragmentViewContent.setPadding(vPadding, vPadding, vPadding, vPadding);

        mTextView.setGravity(Gravity.START);
        mTextView.setPadding(vPadding, vPadding, vPadding, vPadding);
        mTextView.setLayoutParams(new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT));
        mTextView.setTextSize(w.tApp.mTextSize);
        mTextView.setTextAppearance(w.tApp, android.R.attr.textAppearanceLarge);
        mTextView.setText("Messages:");
	}

	public void restore(Bundle vBundle)
	{
		if (vBundle != null) {
		}
	}

	public void save(Bundle vBundle)
	{
		if (vBundle != null) {
		}
	}
}
