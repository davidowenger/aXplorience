package z.a;

import android.app.Activity;
import android.app.Fragment;
import android.os.Bundle;
import android.text.InputType;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.view.inputmethod.EditorInfo;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.FrameLayout;
import android.widget.ImageButton;
import android.widget.LinearLayout;
import android.widget.Spinner;
import android.widget.TextView;

public class TFragmentDrop extends Fragment implements AdapterView.OnItemSelectedListener
{
    // setHasOptionsMenu() during onCreate() for onCreateOptionsMenu() and onOptionsItemSelected() to be called
    // registerForContextMenu() for onCreateContextMenu() onContextItemSelected().
    // API 13 void onViewCreated(View view, Bundle vBundle
    public TWrapper w;
    public TApp mTApp;
    public int mTFragmentViewType;
    public String mDBObjectId;
    public DBObject mDBObject;
    public boolean mEdited;

    public LinearLayout mTFragmentView;
    public TextView mCategory;
    public TextView mTitle;
    public TextView mText;
    public TextView mLink;
    public ImageButton mImageButton;

    public Spinner mEditCategory;
    public EditText mEditTitle;
    public EditText mEditText;
    public EditText mEditLink;
    public ImageButton mButtonDelete;
    public ImageButton mButtonSave;

    public TFragmentDrop()
    {
        super();
        mTApp = null;
        mTFragmentView = null;
        mTFragmentViewType = -1;
        mDBObject = null;
        mDBObjectId = null;
        mEdited = false;
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
        super.onCreate(vBundle);
        setHasOptionsMenu(true);
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup parentView, Bundle vBundle)
    {
        // Input from init() or from Bundle is now ok
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
    }

    @Override
    public void onPause()
    {
        super.onPause();
    }

    @Override
    public void onSaveInstanceState(Bundle vBundle)
    {
        super.onSaveInstanceState(vBundle);
        save(vBundle);
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

        if (mTFragmentViewType == TApp.VIEW_DETAILS && w.tApp.mConfiguration.screenWidthDp >= 480) {
            MenuItem vMenuItemAdd = menu.add(Menu.NONE, TWrapper.ITEM_ADD, 1, "Add");
            vMenuItemAdd.setIcon(w.tApp.maDrawable[10]);
            vMenuItemAdd.setShowAsAction(MenuItem.SHOW_AS_ACTION_IF_ROOM);
        }
        if (mTFragmentViewType == TApp.VIEW_DETAILS) {
            MenuItem vDelete = menu.add(Menu.NONE, TWrapper.ITEM_DELETE, 1, "Delete");
            vDelete.setIcon(w.tApp.maDrawable[8]);
            vDelete.setShowAsAction(MenuItem.SHOW_AS_ACTION_IF_ROOM);

            MenuItem vEdit = menu.add(Menu.NONE, TWrapper.ITEM_EDIT, 1, "Edit");
            vEdit.setIcon(w.tApp.maDrawable[7]);
            vEdit.setShowAsAction(MenuItem.SHOW_AS_ACTION_IF_ROOM);
        }
        if (mTFragmentViewType == TApp.VIEW_EDIT || mTFragmentViewType == TApp.VIEW_ADD) {
            MenuItem vSave = menu.add(Menu.NONE, TWrapper.ITEM_SAVE, 2, "Save");
            vSave.setIcon(w.tApp.maDrawable[9]);
            vSave.setShowAsAction(MenuItem.SHOW_AS_ACTION_IF_ROOM);
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

        if (id == TWrapper.ITEM_EDIT) {
            w.tApp.setView(TApp.VIEW_EDIT, mDBObjectId);
            ret = true;
        }
        if (id == TWrapper.ITEM_DELETE) {
            deleteDBObject();
            w.tApp.setView(TApp.VIEW_HOME, "");
            ret = true;
        }
        if (id == TWrapper.ITEM_SAVE) {
            saveDBObject();
            w.tApp.setView(TApp.VIEW_DETAILS, mDBObjectId);
            ret = true;
        }
        return ret || super.onOptionsItemSelected(item);
    }

    public void deleteDBObject()
    {
        mDBObject.set("archived", w.dbh.TRUE);
        mDBObject.commit();
        w.tApp.populate(w.tApp.getContentView());
    }

    public void init(int vViewType, String vDBObjectId)
    {
        mTFragmentViewType = vViewType;
        mDBObjectId = vDBObjectId;
    }

    public void initContext(TApp vTApp)
    {
        mTApp = vTApp;
        mTFragmentView = new LinearLayout(mTApp);
    }

    public void initData(TWrapper w)
    {
        this.w = w;
    }

    public void initView()
    {
        int vPadding = (int)(10*w.tApp.mDensity);
        boolean vIsIdOk = !mDBObject.get("id").equals("");

        mTFragmentView.removeAllViews();
        mTFragmentView.setPadding(vPadding, vPadding, vPadding, vPadding);
        mTFragmentView.setGravity(Gravity.END|Gravity.TOP);
        mTFragmentView.setOrientation(LinearLayout.VERTICAL);
        mTFragmentView.setLayoutParams(new FrameLayout.LayoutParams(FrameLayout.LayoutParams.MATCH_PARENT, FrameLayout.LayoutParams.MATCH_PARENT));
        mTFragmentView.setBackgroundColor(w.tApp.maColorBase[15]);

        if (mTFragmentViewType == TApp.VIEW_DETAILS && vIsIdOk) {
            // Create a view for the details of the message
            mTFragmentView.setId(0xFAE3);
            mCategory = new TextView(w.tApp);
            mTitle = new TextView(w.tApp);
            mText = new TextView(w.tApp);
            mLink = new TextView(w.tApp);

            mCategory.setGravity(Gravity.START);
            mCategory.setPadding(vPadding, vPadding, vPadding, vPadding);
            mCategory.setLayoutParams(new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT));
            mCategory.setBackgroundColor(w.tApp.maColorBase[parse(mDBObject.get("id_cat"))*3+2]);
            mCategory.setTextSize(w.tApp.mTextSize);
            mCategory.setTypeface(mCategory.getTypeface(), 1);
            mCategory.setText(w.tApp.maCategory[parse(mDBObject.get("id_cat"))]);

            mTitle.setGravity(Gravity.START);
            mTitle.setPadding(vPadding, vPadding, vPadding, vPadding);
            mTitle.setLayoutParams(new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT));
            mTitle.setTextSize(w.tApp.mTextSize);
            mTitle.setTypeface(mTitle.getTypeface(), 1);
            mTitle.setText(mDBObject.get("title"));

            mText.setGravity(Gravity.START);
            mText.setPadding(vPadding, vPadding, vPadding, vPadding);
            mText.setLayoutParams(new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT));
            mText.setTextSize(w.tApp.mTextSize);
            mText.setText(mDBObject.get("text"));

            mLink.setGravity(Gravity.START);
            mLink.setPadding(vPadding, vPadding, vPadding, vPadding);
            mLink.setLayoutParams(new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT));
            mLink.setTextSize(w.tApp.mTextSize);
            mLink.setText(mDBObject.get("link"));

            mTFragmentView.addView(mCategory);
            mTFragmentView.addView(mTitle);
            mTFragmentView.addView(mText);
            mTFragmentView.addView(mLink);
        }
        if (
            (mTFragmentViewType == TApp.VIEW_EDIT && vIsIdOk) ||
            (mTFragmentViewType == TApp.VIEW_ADD)
        ) {
            // Create a view for the editing the message
            mTFragmentView.setId(0xFAE4);
            mEditCategory = new Spinner(w.tApp);
            mEditTitle = new EditText(w.tApp);
            mEditText = new EditText(w.tApp);
            mEditLink = new EditText(w.tApp);

            ArrayAdapter<String> vArrayAdapter = new ArrayAdapter<String>(w.tApp, R.layout.spinner_items, w.tApp.maCategory);
            vArrayAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);

            mEditCategory.setId(22222222);
            mEditCategory.setGravity(Gravity.START);
            mEditCategory.setPadding(vPadding, vPadding, vPadding, vPadding);
            mEditCategory.setLayoutParams(new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT));
            mEditCategory.setAdapter(vArrayAdapter);
            mEditCategory.setOnItemSelectedListener(this);
            mEditCategory.setSelection(parse(mDBObject.get("id_cat")));

            mEditTitle.setRawInputType(InputType.TYPE_CLASS_TEXT|InputType.TYPE_TEXT_VARIATION_NORMAL);
            mEditTitle.setImeOptions(EditorInfo.IME_ACTION_NEXT|EditorInfo.IME_FLAG_NO_FULLSCREEN|EditorInfo.IME_FLAG_NO_EXTRACT_UI);
            mEditTitle.setGravity(Gravity.START);
            mEditTitle.setPadding(vPadding, vPadding, vPadding, vPadding);
            mEditTitle.setLayoutParams(new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT));
            mEditTitle.setTextSize(w.tApp.mTextSize);
            mEditTitle.setTextAppearance(w.tApp, android.R.attr.textAppearanceLarge);
            mEditTitle.setText(mDBObject.get("title"));
            mEditTitle.setHint("Short message");

            mEditText.setRawInputType(InputType.TYPE_CLASS_TEXT|InputType.TYPE_TEXT_VARIATION_NORMAL|InputType.TYPE_TEXT_FLAG_MULTI_LINE);
            mEditText.setImeOptions(EditorInfo.IME_FLAG_NO_FULLSCREEN|EditorInfo.IME_FLAG_NO_EXTRACT_UI|EditorInfo.IME_FLAG_NAVIGATE_NEXT);
            mEditText.setGravity(Gravity.START);
            mEditText.setPadding(vPadding, vPadding, vPadding, vPadding);
            mEditText.setLayoutParams(new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT));
            mEditText.setTextSize(w.tApp.mTextSize);
            mEditText.setTextAppearance(w.tApp, android.R.attr.textAppearanceLarge);
            mEditText.setText(mDBObject.get("text"));
            mEditText.setHint("More description ...");

            mEditLink.setRawInputType(InputType.TYPE_CLASS_TEXT|InputType.TYPE_TEXT_VARIATION_URI|InputType.TYPE_TEXT_FLAG_NO_SUGGESTIONS);
            mEditLink.setImeOptions(EditorInfo.IME_ACTION_DONE|EditorInfo.IME_FLAG_NO_FULLSCREEN|EditorInfo.IME_FLAG_NO_EXTRACT_UI);
            mEditLink.setGravity(Gravity.START);
            mEditLink.setPadding(vPadding, vPadding, vPadding, vPadding);
            mEditLink.setLayoutParams(new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT));
            mEditLink.setTextSize(w.tApp.mTextSize);
            mEditLink.setTextAppearance(w.tApp, android.R.attr.textAppearanceLarge);
            mEditLink.setText(mDBObject.get("link"));
            mEditLink.setHint("Your url");

            mTFragmentView.addView(mEditCategory);
            mTFragmentView.addView(mEditTitle);
            mTFragmentView.addView(mEditText);
            mTFragmentView.addView(mEditLink);

            mEdited = true;
        }
        if (mTFragmentViewType != TApp.VIEW_ADD && !vIsIdOk) {
            //System.out.println("No good id forces VIEW_HOME from DROP");
            w.tApp.setView(TApp.VIEW_HOME, "");
        }
    }

    public void onItemSelected(AdapterView<?> parent, View view, int pos, long id)
    {
    }

    public void onNothingSelected(AdapterView<?> parent)
    {
    }

    public int parse(String vString)
    {
        int ret = 0;

        try {
            ret = Integer.parseInt(vString);
        } catch (Exception e) {
            //System.out.println(e.getMessage());
        }
        return ret;
    }

    public void restore(Bundle vBundle)
    {
        if (vBundle != null) {
            mTFragmentViewType = vBundle.getInt("mTFragmentViewType");
            mDBObjectId = vBundle.getString("mDBObjectId");
            mEdited = vBundle.getBoolean("mEdited");
        }
        mDBObject = w.dbh.get("Drop").getInstance(mDBObjectId);

        if (vBundle != null && mEdited) {
            mDBObject.set("id_cat", vBundle.getString("mEditCategory"));
            mDBObject.set("title", vBundle.getString("mEditTitle"));
            mDBObject.set("text", vBundle.getString("mEditText"));
            mDBObject.set("link", vBundle.getString("mEditLink"));
        }
    }

    public void save(Bundle vBundle)
    {
        if (vBundle != null) {
            vBundle.putInt("mTFragmentViewType", mTFragmentViewType);
            vBundle.putString("mDBObjectId", mDBObjectId);
            vBundle.putBoolean("mEdited", mEdited);
        }
        if (vBundle != null && mEdited && mEditCategory != null) {
            vBundle.putString("mEditCategory", "" + mEditCategory.getSelectedItemPosition());
            vBundle.putString("mEditTitle", "" + mEditTitle.getText());
            vBundle.putString("mEditText", "" + mEditText.getText());
            vBundle.putString("mEditLink", "" + mEditLink.getText());
        }
    }

    public void saveDBObject()
    {
        mDBObject = w.boSeed.setSeed(
            mDBObject,
            "" + mEditCategory.getSelectedItemPosition(),
            "" + mEditTitle.getText(),
            "" + mEditText.getText(),
            "" + mEditLink.getText()
        ).mDBObject;
        mDBObjectId = mDBObject.get("id");
        w.tApp.populate(w.tApp.getContentView());
    }
}
