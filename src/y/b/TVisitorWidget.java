package y.b;

import android.content.Context;
import android.graphics.drawable.Drawable;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AbsSpinner;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.Button;
import android.widget.CompoundButton;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.Spinner;
import android.widget.SpinnerAdapter;
import android.widget.TextView.BufferType;
import android.widget.ToggleButton;

public class TVisitorWidget extends TVisitor
{
    public final BufferType[] maBufferType = BufferType.values();

    public TVisitorWidget(TWrapper w) {
        super(w);
    }

    //******************************************************************************************
    //************************************ AbsSpinner ******************************************
    //******************************************************************************************
    // void setSelection(int position)
    public long visit(TAlpha00 element, long a, long b, long c, long d, long e)
    {
        ((AbsSpinner)w.sObject.get(a)).setSelection((int)b);
        return 0;
    }

    //******************************************************************************************
    //************************************ BaseAdapter *****************************************
    //******************************************************************************************
    // TBaseAdapter(TWrapper w, long n)
    public long visit(TBeta00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new TBaseAdapter(w, a));
        return 0;
    }

    // View* getDropDownView(int position, View* convertView, ViewGroup* parent)
    public long visit(TGamma00 element, long a, long b, long c, long d, long e)
    {
        return w.tFrame.putKey(b, ((TBaseAdapter)w.sObject.get(a)).getDropDownViewParent((int)c, (View)w.sObject.get(d), (ViewGroup)w.sObject.get(e)));
    }

    //******************************************************************************************
    //************************************ Button **********************************************
    //******************************************************************************************
    // Button(Context* context)
    public long visit(TIota00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new Button((Context)w.sObject.get(b)));
        return 0;
    }

    //******************************************************************************************
    //********************************** CompoundButton ****************************************
    //******************************************************************************************
    // CompoundButton()
    //

    // void setButtonDrawable(Drawable* d)
    public long visit(TLambda00 element, long a, long b, long c, long d, long e)
    {
        ((CompoundButton)w.sObject.get(a)).setButtonDrawable(w.tFrame.getValue(b, Drawable.class));
        return 0;
    }

    // bool isChecked()
    public long visit(TOmega00 element, long a, long b, long c, long d, long e)
    {
        return (((CompoundButton)w.sObject.get(a)).isChecked() ? 1 : 0 );
    }

    //******************************************************************************************
    //************************************* EditText *******************************************
    //******************************************************************************************
    // EditText(Context* context)
    public long visit(TMu00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new EditText((Context)w.sObject.get(b)));
        return 0;
    }

    // String getText()
    public long visit(TNu00 element, long a, long b, long c, long d, long e)
    {
        String vString = null;

        try {
            vString = new String(((EditText)w.sObject.get(a)).getText().toString().getBytes("UTF-8"), "UTF-8");
        }
        catch (Exception vException) {
            if (w.doDebug) vException.printStackTrace();
            vString = null;
        }
        return w.tFrame.putNext(vString);
    }

    // void setText(const String& text, TextView::BufferType type)
    public long visit(TXi00 element, long a, long b, long c, long d, long e)
    {
        ((EditText)w.sObject.get(a)).setText((String)w.tFrame.nRunObject(b), maBufferType[(int)c]);
        return 0;
    }

    //******************************************************************************************
    //********************************* ImageButton ********************************************
    //******************************************************************************************
    // ImageButton(Context* context)
    public long visit(TOmicron00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new ImageButton((Context)w.sObject.get(b)));
        return 0;
    }

    //******************************************************************************************
    //************************************** Spinner *******************************************
    //******************************************************************************************
    // Spinner(Context* context)
    public long visit(TPi00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new Spinner((Context)w.sObject.get(b)));
        return 0;
    }

    // void setGravity(int gravity)
    public long visit(TRho00 element, long a, long b, long c, long d, long e)
    {
        ((Spinner)w.sObject.get(a)).setGravity((int)b);
        return 0;
    }

    // void setOnItemClickListener(AdapterView::OnItemClickListener* l)
    public long visit(TSigma00 element, long a, long b, long c, long d, long e)
    {
        ((Spinner)w.sObject.get(a)).setOnItemClickListener((OnItemClickListener)w.sObject.get(b));
        return 0;
    }

    // void setAdapter(SpinnerAdapter* adapter)
    public long visit(TTau00 element, long a, long b, long c, long d, long e)
    {
        ((Spinner)w.sObject.get(a)).setAdapter((SpinnerAdapter)w.sObject.get(b));
        return 0;
    }

    //******************************************************************************************
    //********************************* ToggleButton *******************************************
    //******************************************************************************************
    // ToggleButton(Context* context)
    public long visit(TUpsilon00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new ToggleButton((Context)w.sObject.get(b)));
        return 0;
    }

    // void setChecked(bool checked)
    public long visit(TPhi00 element, long a, long b, long c, long d, long e)
    {
        ((ToggleButton)w.sObject.get(a)).setChecked( b != 0 ? true : false );
        return 0;
    }

    // void setTextOn(const String& textOn)
    public long visit(TKhi00 element, long a, long b, long c, long d, long e)
    {
        ((ToggleButton)w.sObject.get(a)).setTextOn((String)w.tFrame.nRunObject(b));
        return 0;
    }

    // void setTextOff(const String& textOff)
    public long visit(TPsi00 element, long a, long b, long c, long d, long e)
    {
        ((ToggleButton)w.sObject.get(a)).setTextOff((String)w.tFrame.nRunObject(b));
        return 0;
    }
}
