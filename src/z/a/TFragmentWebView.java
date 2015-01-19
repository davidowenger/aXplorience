//package z.a;
//
//import android.app.Activity;
//import android.app.Fragment;
//import android.os.Bundle;
//import android.view.LayoutInflater;
//import android.view.Menu;
//import android.view.MenuInflater;
//import android.view.MenuItem;
//import android.view.View;
//import android.view.ViewGroup;
//import android.webkit.WebView;
//import android.widget.LinearLayout;
//import android.widget.ScrollView;
//import android.widget.TextView;
//
////<uses-permission
////    android:name="android.permission.INTERNET"
/////>
//public class TFragmentWebView extends Fragment
//{
//	// setHasOptionsMenu() during onCreate() for onCreateOptionsMenu() and onOptionsItemSelected() to be called
//	// registerForContextMenu() for onCreateContextMenu() onContextItemSelected().
//	// API 13 void onViewCreated(View view, Bundle vBundle
//	public TWrapper w;
//	public TApp mTApp;
//	public LinearLayout mTFragmentView;
//	public LinearLayout mTFragmentViewBar;
//	public ScrollView mTFragmentViewScroll;
//    public LinearLayout mTFragmentViewContent;
//    public WebView mWebView;
//    public String mUrl;
//
//	public TFragmentWebView()
//	{
//		super();
//	}
//
//    @Override
//    public void onAttach(Activity vActivity)
//    {
//        super.onAttach(vActivity);
//        initContext((TApp)vActivity);
//    }
//
//    @Override
//    public void onCreate(Bundle vBundle)
//    {
//        // Input from init() or from Bundle is now ok
//        super.onCreate(vBundle);
//        restore(vBundle);
//    }
//
//    @Override
//	public View onCreateView(LayoutInflater inflater, ViewGroup parentView, Bundle vBundle)
//	{
//        initView();
//        return mTFragmentView;
//	}
//
//    @Override
//	public void onActivityCreated(Bundle vBundle)
//	{
//        // Members from Activity are now ok
//        super.onActivityCreated(vBundle);
//        initResources(mTApp.w);
//        save(vBundle);
//	}
//
//    @Override
//    public void onViewStateRestored(Bundle vBundle)
//    {
//        super.onViewStateRestored(vBundle);
//    }
//
//    @Override
//	public void onStart()
//	{
//		super.onStart();
//	}
//
//    @Override
//	public void onResume()
//	{
//		super.onResume();
//	}
//
//    @Override
//	public void onPause()
//	{
//		super.onPause();
//	}
//
//    @Override
//    public void onSaveInstanceState(Bundle vBundle)
//    {
//        save(vBundle);
//        super.onSaveInstanceState(vBundle);
//    }
//
//    @Override
//	public void onStop()
//	{
//		super.onStop();
//	}
//
//    @Override
//	public void onDestroyView()
//	{
//		super.onDestroyView();
//	}
//
//    @Override
//	public void onDestroy()
//	{
//		super.onDestroy();
//	}
//
//    @Override
//	public void onDetach()
//	{
//		super.onDetach();
//	}
//
//    @Override
//    public void onCreateOptionsMenu(Menu menu, MenuInflater inflater)
//    {
//        menu.removeItem(TWrapper.ITEM_EDIT);
//        menu.removeItem(TWrapper.ITEM_DELETE);
//        menu.removeItem(TWrapper.ITEM_SAVE);
//        menu.removeItem(TWrapper.ITEM_ADD);
//        super.onCreateOptionsMenu(menu, inflater);
//    }
//
//    @Override
//    public void onPrepareOptionsMenu(Menu menu)
//    {
//        super.onPrepareOptionsMenu(menu);
//    }
//
//    @Override
//    public boolean onOptionsItemSelected(MenuItem item)
//    {
//        return super.onOptionsItemSelected(item);
//    }
//
//    public void init()
//    {
//    }
//
//    public void initContext(TApp vTApp)
//    {
//        mTApp = vTApp;
//        mTFragmentView = new LinearLayout(mTApp);
//        mTFragmentViewScroll = new ScrollView(mTApp);
//        mTFragmentViewContent = new LinearLayout(mTApp);
//        mUrl = "http://www.facebook.com";
//
//        mTFragmentViewContent.setId(0x12421);
//        TextView vTextView = new TextView(mTApp);
//        vTextView.setText("Messages:");
//        System.out.println("fragment: " + this.getId());
//
//        mTFragmentViewScroll.addView(mTFragmentViewContent);
//        mTFragmentView.addView(vTextView);
//        mTFragmentView.addView(mTFragmentViewScroll);
//        mTFragmentView.setId(0xFAE0);
//
//        setHasOptionsMenu(true);
//    }
//
//    public void initView()
//    {
//    }
//
//    public void initResources(TWrapper w)
//    {
//		this.w = w;
//
//		int vPadding = (int)(5*w.tApp.mDensity);
//
//		WebView mWebView = new WebView(this);
//		mWebView.setWebViewClient(new Callback());
//		mWebView.loadUrl(mUrl);
//
//
//
//
//        mTFragmentView.setOrientation(LinearLayout.VERTICAL);
//		mTFragmentView.setLayoutParams(new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.MATCH_PARENT));
//
//        mTFragmentViewContent.setOrientation(LinearLayout.VERTICAL);
//		mTFragmentViewContent.setPadding(vPadding, vPadding, vPadding, vPadding);
//
//		//mTFragmentViewBar.setBackgroundColor(w.tApp.maColor[8]);
//
////		mButtonAll = new ToggleButton(w.tApp);
////		mButtonAllListener = new TButtonAllListener(w);
////
////		mButtonAll.setLayoutParams(new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1));
////		mButtonAll.setBackgroundColor(0x00000000);
////		mButtonAll.setTextSize(20);
////		mButtonAll.setGravity(Gravity.CENTER);
////		mButtonAll.setText("All");
////		mButtonAll.setTextOn("All");
////		mButtonAll.setTextOff("All");
////		mButtonAll.setOnClickListener(mButtonAllListener);
////
////		mButtonEdit = new Button(w.tApp);
////		mButtonEditListener = new TButtonEditListener(w);
////
////		mButtonEdit.setLayoutParams(new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1));
////		mButtonEdit.setBackgroundColor(0x00000000);
////		mButtonEdit.setTextSize(20);
////		mButtonEdit.setGravity(Gravity.CENTER);
////		mButtonEdit.setText("Edit");
////		mButtonEdit.setOnClickListener(mButtonEditListener);
////
////		mButtonDelete = new Button(w.tApp);
////		mButtonDeleteListener = new TButtonDeleteListener(w);
////
////		mButtonDelete.setLayoutParams(new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1));
////		mButtonDelete.setBackgroundColor(0x00000000);
////		mButtonDelete.setTextSize(20);
////		mButtonDelete.setGravity(Gravity.CENTER);
////		mButtonDelete.setText("Del");
////		mButtonDelete.setOnClickListener(mButtonDeleteListener);
////
////		mButtonAdd = new Button(w.tApp);
////		mButtonAddListener = new TButtonAddListener(w);
////
////		mButtonAdd.setLayoutParams(new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1));
////		mButtonAdd.setBackgroundColor(0x00000000);
////		mButtonAdd.setTextSize(20);
////		mButtonAdd.setGravity(Gravity.CENTER);
////		mButtonAdd.setText("Add");
////		mButtonAdd.setOnClickListener(mButtonAddListener);
//
////		mTFragmentViewBar.addView(mButtonAll);
////		mTFragmentViewBar.addView(mButtonEdit);
////		mTFragmentViewBar.addView(mButtonDelete);
////		mTFragmentViewBar.addView(mButtonAdd);
//
//	}
//
//	public void restore(Bundle vBundle)
//	{
//		if (vBundle != null) {
//		}
//	}
//
//	public void save(Bundle vBundle)
//	{
//		if (vBundle != null) {
//		}
//	}
//}
