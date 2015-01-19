package z.a;

import android.graphics.drawable.ColorDrawable;
import android.graphics.drawable.StateListDrawable;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ToggleButton;

public class TWidgetMessage extends LinearLayout
{
	public TWrapper w;
	public ImageButton mButtonCategory;
	public TButtonCategoryListener mTButtonCategoryListener;
	public Button mButtonText;
	public TButtonTextListener mTButtonTextListener;
	public ToggleButton mButtonCheck;
	public TButtonCheckListener mTButtonCheckListener;
	public ToggleButton mButtonBuzz;
	public TButtonBuzzListener mTButtonBuzzListener;
	public StateListDrawable mStateListCheck;
	public StateListDrawable mStateListBuzz;
	public BO_Drop mBODrop;
	public DBObject mDBDrop;
	public boolean mIsSelected;
	public boolean mIsEnabled;
	public int mIdCategory;

	public TWidgetMessage(TWrapper w, BO_Drop drop)
	{
		super(w.context);

		this.w = w;
		mBODrop = drop;
    	mDBDrop = mBODrop.mDBObject;
    	mIdCategory = Integer.parseInt(mDBDrop.get("id_cat"));
    	mIsSelected = false;

		setOrientation(LinearLayout.HORIZONTAL);
		setGravity(Gravity.LEFT);
		setBackgroundColor(0xFFFFFFFF);

		LinearLayout.LayoutParams lp = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT);
		lp.setMargins(5, 5, 5, 5);
		setLayoutParams(lp);

		init();
	}

	public void init()
	{
		mButtonCategory = new ImageButton(w.tApp);
		mButtonCategory.setPadding((int)(5*w.tApp.mDensity), 5, (int)(15*w.tApp.mDensity), 5);
		mButtonCategory.setBackground(null);
		mButtonCategory.setImageDrawable(new ColorDrawable(w.tApp.maColorBase[mIdCategory*3+2]));
		mButtonCategory.setScaleType(ImageView.ScaleType.FIT_XY);

		mTButtonCategoryListener = new TButtonCategoryListener(w, this);
		mButtonCategory.setOnClickListener(mTButtonCategoryListener);

		int nWidth = (int)(7*w.tApp.mDensity)+mButtonCategory.getPaddingLeft()+mButtonCategory.getPaddingRight();
		LinearLayout.LayoutParams vLayoutParams = new LinearLayout.LayoutParams(nWidth, LinearLayout.LayoutParams.MATCH_PARENT);
		vLayoutParams.setMargins(0, 0, 0, 0);
		mButtonCategory.setLayoutParams(vLayoutParams);

		mButtonText = new Button(w.tApp);
		mTButtonTextListener = new TButtonTextListener(w, this);

		mButtonText.setOnClickListener(mTButtonTextListener);
		mButtonText.setLayoutParams(new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1));
		mButtonText.setPadding(5,5,5,5);
		mButtonText.setLines(1);
		mButtonText.setBackground(null);
		mButtonText.setBackgroundColor(0x00000000);
        mButtonText.setGravity(Gravity.LEFT|Gravity.CLIP_HORIZONTAL);
		mButtonText.setTextSize(w.tApp.mTextSize);
        mButtonText.setTextAppearance(w.tApp, android.R.attr.textAppearanceLarge);
		mButtonText.setText(mDBDrop.get("title"));

	    mButtonCheck = new ToggleButton(w.tApp);
	    mTButtonCheckListener = new TButtonCheckListener(w, this);

	    mButtonCheck.setOnClickListener(mTButtonCheckListener);
	    mButtonCheck.setBackground(null);
	    mButtonCheck.setButtonDrawable(mStateListCheck);
	    mButtonCheck.setLayoutParams(new ViewGroup.LayoutParams(w.tApp.maDrawable[3].getIntrinsicWidth(), w.tApp.maDrawable[3].getIntrinsicHeight()));
	    mButtonCheck.setPadding(0,0,0,0);
	    mButtonCheck.setText("");
	    mButtonCheck.setTextOn("");
	    mButtonCheck.setTextOff("");
	    mButtonCheck.setEnabled(true);
	    mButtonCheck.setChecked(mDBDrop.get("checked").equals(w.dbh.TRUE));

	    mButtonBuzz = new ToggleButton(w.tApp);
	    mTButtonBuzzListener = new TButtonBuzzListener(w, this);

	    mButtonBuzz.setOnClickListener(mTButtonBuzzListener);
	    mButtonBuzz.setBackground(null);
	    mButtonBuzz.setButtonDrawable(mStateListBuzz);
	    mButtonBuzz.setLayoutParams(new ViewGroup.LayoutParams(w.tApp.maDrawable[3].getIntrinsicWidth(), w.tApp.maDrawable[3].getIntrinsicHeight()));
	    mButtonBuzz.setPadding(0,0,0,0);
	    mButtonBuzz.setText("");
	    mButtonBuzz.setTextOn("");
	    mButtonBuzz.setTextOff("");
	    mButtonBuzz.setEnabled(mButtonCheck.isChecked());
	    mButtonBuzz.setChecked(mDBDrop.get("buzzed").equals(w.dbh.TRUE));

		LinearLayout left = new LinearLayout(w.tApp);
		left.setLayoutParams(new TWidgetMessage.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1));
		left.setPadding(0,0,0,0);
		left.setOrientation(LinearLayout.HORIZONTAL);
		left.setGravity(Gravity.LEFT);

		LinearLayout right = new LinearLayout(w.tApp);
		right.setLayoutParams(new TWidgetMessage.LayoutParams(LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT));
		right.setPadding(0,0,0,0);
		right.setOrientation(LinearLayout.HORIZONTAL);
		right.setGravity(Gravity.LEFT);

		left.addView(mButtonCategory);
		left.addView(mButtonText);
		right.addView(mButtonCheck);
		right.addView(mButtonBuzz);
		addView(left);
		addView(right);
	}

	public void setState(boolean vState)
	{
		mIsSelected = vState;
		setState();
	}

	public void setState()
	{
		mIsEnabled = w.tApp.maCategorySelected[mIdCategory];
		w.tApp.mIsAllChecked &= mIsSelected;

		if (mIsEnabled) {
			setVisibility(VISIBLE);
		}
    	if (mIsEnabled && mIsSelected) {
    		w.aMessageSelected.add(this);
    		setBackgroundColor(w.tApp.maColor[7]);
    	}
    	if (!mIsEnabled) {
			setVisibility(GONE);
    	}
    	if (!mIsEnabled || !mIsSelected) {
			w.aMessageSelected.remove(this);
			setBackgroundColor(w.tApp.maColor[6]);
		}
	}
}

class TWidgetInboundMessage extends TWidgetMessage
{
	public TWidgetInboundMessage(TWrapper w, BO_Drop drop)
	{
		super(w, drop);
	}

	public void init()
	{
		mStateListCheck = new StateListDrawable();
		mStateListCheck.addState(new int[] { android.R.attr.state_enabled, android.R.attr.state_checked }, w.tApp.maDrawable[4]);
		mStateListCheck.addState(new int[] { android.R.attr.state_enabled }, w.tApp.maDrawable[3]);

		mStateListBuzz = new StateListDrawable();
		mStateListBuzz.addState(new int[] { android.R.attr.state_enabled, android.R.attr.state_checked  }, w.tApp.maDrawable[1]);
		mStateListBuzz.addState(new int[] { android.R.attr.state_enabled }, w.tApp.maDrawable[2]);
		mStateListBuzz.addState(new int[0], w.tApp.maDrawable[0]);

		super.init();
	}
}

class TWidgetOutboundMessage extends TWidgetMessage
{
	public TWidgetOutboundMessage(TWrapper w, BO_Drop drop)
	{
		super(w, drop);
	}

	public void init()
	{
		mStateListCheck = new StateListDrawable();
		mStateListCheck.addState(new int[] { android.R.attr.state_enabled, android.R.attr.state_checked }, w.tApp.maDrawable[6]);
		mStateListCheck.addState(new int[] { android.R.attr.state_enabled }, w.tApp.maDrawable[5]);

		mStateListBuzz = new StateListDrawable();
		mStateListBuzz.addState(new int[] { android.R.attr.state_enabled }, w.tApp.maDrawable[0]);
		mStateListBuzz.addState(new int[0], w.tApp.maDrawable[0]);

		super.init();

		mButtonCheck.setChecked(true);
		mButtonBuzz.setEnabled(true);
	}
}

class TButtonCategoryListener implements View.OnClickListener
{
	public TWrapper w;
	public TWidgetMessage mTWidgetMessage;

	TButtonCategoryListener(TWrapper w, TWidgetMessage mTWidgetMessage)
	{
		this.w = w;
		this.mTWidgetMessage = mTWidgetMessage;
	}

    public void onClick(View view)
    {
    	//w.tApp.maCategorySelected[mTWidgetMessage.mIdCategory] = false;
    	//w.tApp.setAllState();
    }
}

class TButtonTextListener implements View.OnClickListener
{
	public TWrapper w;
	public TWidgetMessage mTWidgetMessage;

	TButtonTextListener(TWrapper w, TWidgetMessage mTWidgetMessage)
	{
		this.w = w;
		this.mTWidgetMessage = mTWidgetMessage;
	}

    public void onClick(View view)
    {
    	//mTWidgetMessage.setState(!mTWidgetMessage.mIsSelected);
		//w.tApp.setState();
    	w.tApp.setView(TApp.VIEW_DETAILS, mTWidgetMessage.mDBDrop.get("id"));
    }
}

class TButtonCheckListener implements View.OnClickListener
{
	public TWrapper w;
	public TWidgetMessage mTWidgetMessage;

	TButtonCheckListener(TWrapper w, TWidgetMessage mTWidgetMessage)
	{
		this.w = w;
		this.mTWidgetMessage = mTWidgetMessage;
	}

    public void onClick(View view)
    {
    	boolean checked = mTWidgetMessage.mButtonCheck.isChecked();
		mTWidgetMessage.mButtonBuzz.setChecked(mTWidgetMessage.mDBDrop.get("buzzed").equals(w.dbh.TRUE));
    	mTWidgetMessage.mButtonBuzz.setEnabled(checked);
    	mTWidgetMessage.mDBDrop.set("checked", ( checked ? w.dbh.TRUE : w.dbh.FALSE )).commit();
    }
}

class TButtonBuzzListener implements View.OnClickListener
{
	public TWrapper w;
	public TWidgetMessage mTWidgetMessage;

	TButtonBuzzListener(TWrapper w, TWidgetMessage mTWidgetMessage)
	{
		this.w = w;
		this.mTWidgetMessage = mTWidgetMessage;
	}

    public void onClick(View view)
    {
        boolean checked = mTWidgetMessage.mButtonBuzz.isChecked();
        mTWidgetMessage.mDBDrop.set("buzzed",  ( checked  ? w.dbh.TRUE : w.dbh.FALSE )).commit();
    	//mTWidgetMessage.mButtonBuzz.setChecked(false);
    }
}
