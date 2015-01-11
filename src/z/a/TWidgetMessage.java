package z.a;

import java.text.DateFormat;
import java.util.ArrayList;
import java.util.Date;

import android.content.Intent;
import android.graphics.drawable.StateListDrawable;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.ToggleButton;

public class TWidgetMessage extends LinearLayout
{
	public TWrapper w;
	public ToggleButton mButtonCheck;
	public ToggleButton mButtonBuzz;
	public StateListDrawable mStateListCheck;
	public StateListDrawable mStateListBuzz;
	public BO_Drop mBODrop;
	public DBObject mDBDrop;
	public boolean mState;
	
	public TWidgetMessage(TWrapper w, BO_Drop drop)
	{
		super(w.context);

		this.w = w;
		mBODrop = drop;
    	mDBDrop = mBODrop.mDBObject;
    	mState = false;
    	
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
		String id_cat = mBODrop.mDBObject.get("id_cat");
		String date = mBODrop.mDBObject.get("date");
		String text = mBODrop.mDBObject.get("text");
		int nCat = Integer.parseInt(id_cat);

		mStateListBuzz = new StateListDrawable();
		mStateListBuzz.addState(new int[] { android.R.attr.state_enabled, android.R.attr.state_pressed }, w.tApp.maDrawable[2]);
		mStateListBuzz.addState(new int[] { android.R.attr.state_enabled }, w.tApp.maDrawable[1]);
		mStateListBuzz.addState(new int[0], w.tApp.maDrawable[0]);

	    ToggleButton mButtonCheck = new ToggleButton(w.tApp);
	    mButtonCheck.setBackground(null);
	    mButtonCheck.setButtonDrawable(mStateListCheck);
	    mButtonCheck.setLayoutParams(new ViewGroup.LayoutParams(w.tApp.maDrawable[3].getIntrinsicWidth(), w.tApp.maDrawable[3].getIntrinsicHeight()));
	    mButtonCheck.setPadding(0,0,0,0);
	    mButtonCheck.setText("");
	    mButtonCheck.setTextOn("");
	    mButtonCheck.setTextOff("");
	    mButtonCheck.setEnabled(true);
	    mButtonCheck.setChecked(false);

	    ToggleButton mButtonBuzz = new ToggleButton(w.tApp);
	    mButtonBuzz.setBackground(null);
	    mButtonBuzz.setButtonDrawable(mStateListBuzz);
	    mButtonBuzz.setLayoutParams(new ViewGroup.LayoutParams(w.tApp.maDrawable[3].getIntrinsicWidth(), w.tApp.maDrawable[3].getIntrinsicHeight()));
	    mButtonBuzz.setPadding(0,0,0,0);
	    mButtonBuzz.setText("");
	    mButtonBuzz.setTextOn("");
	    mButtonBuzz.setTextOff("");
	    mButtonBuzz.setEnabled(false);
	    mButtonBuzz.setChecked(false);

		LinearLayout left = new LinearLayout(w.tApp);
		left.setLayoutParams(new TWidgetMessage.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1));
		left.setOrientation(LinearLayout.HORIZONTAL);
		left.setGravity(Gravity.LEFT);
		left.setPadding(0,0,0,0);

		LinearLayout right = new LinearLayout(w.tApp);
		right.setLayoutParams(new TWidgetMessage.LayoutParams(LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT));
		right.setOrientation(LinearLayout.HORIZONTAL);
		right.setGravity(Gravity.LEFT);
		right.setPadding(0,0,0,0);

		TextView text1 = new TextView(w.tApp);
		text1.setTextSize(20);
		text1.setGravity(Gravity.LEFT);
		text1.setText(
			DateFormat.getTimeInstance().format(new Date(Long.parseLong(date)))
		);

		Button buttonText = new Button(w.tApp);
		TWidgetTextListener buttonTextListener = new TWidgetTextListener(w, this);

		buttonText.setLayoutParams(new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.MATCH_PARENT));
		buttonText.setBackgroundColor(0x00000000);
		buttonText.setTextSize(20);
		buttonText.setGravity(Gravity.LEFT);
		buttonText.setText("ALL");
		buttonText.setOnClickListener(buttonTextListener);
		buttonText.setTextSize(20);
		buttonText.setGravity(Gravity.LEFT);
		buttonText.setText(
			text
		);
		
		left.addView(buttonText);
		right.addView(mButtonCheck);
		right.addView(mButtonBuzz);
		addView(left);
		addView(right);
	}
	
	public void setState(boolean vState)
	{
		mState = vState;
		
    	if (mState) {
    		w.aMessageSelected.add(this);
    		setBackgroundColor(w.tApp.maColor[7]);
    	} else {
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

		super.init();
	}
}

class TWidgetTextListener implements View.OnClickListener
{
	public TWrapper w;
	public TWidgetMessage mTWidgetMessage; 

	TWidgetTextListener(TWrapper w, TWidgetMessage mTWidgetMessage)
	{
		this.w = w;
		this.mTWidgetMessage = mTWidgetMessage;
	}

    public void onClick(View view)
    {
    	mTWidgetMessage.setState(!mTWidgetMessage.mState);
		w.tApp.setState();
    }
}
