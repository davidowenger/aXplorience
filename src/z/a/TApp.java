package z.a;

import android.app.Activity;
import android.os.Bundle;

public class TApp extends Activity
{
	public TWrapper w;
	
    /* Called when the activity is first created */
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        
        w = new TWrapper();
        w.context = getApplication();
        w.tFrame = new TClozer(w);
        w.tFrame.tInit();
        w.view = w.tView.convert();
        setContentView(w.view);
        
    }

    protected void onPause() {
        super.onPause();
        //w.tView.callLong(w.alpha);
    }

    protected void onResume() {
        super.onResume();
        //w.tView.callLong(w.beta);
    }
}     
















//jstring Java_com_example_hellojni_HelloJni_stringFromJNI( JNIEnv* env, jobject thiz )
//return (*env)->NewStringUTF(env, "Hello from JNI !");

//import hashCode.R;

//import android.content.Context;
//import android.content.SharedPreferences;
//import android.view.Gravity;
//import android.view.ViewGroup.LayoutParams;
//import android.widget.AdapterView;
//import android.widget.ArrayAdapter;
//import android.widget.ImageView;
//import android.widget.ImageView.ScaleType;
//import android.widget.LinearLayout;
//import android.widget.Spinner;
//import android.widget.TextView;
//import android.widget.Toast;
//import android.widget.AdapterView.OnItemSelectedListener;
//import android.graphics.Bitmap;
//import android.graphics.Canvas;

//        //setContentView(new AXplorienceView(this));
//        //setContentView(R.layout.main); 
//        TextView label = new TextView(this);  
//        label.setTextSize(20);  
//        label.setGravity(Gravity.CENTER_HORIZONTAL);  
//        ImageView pic = new ImageView(this);  
//        //pic.setImageResource(R.drawable.matterhorn);  
//        pic.setLayoutParams(new LayoutParams(LayoutParams.WRAP_CONTENT, LayoutParams.WRAP_CONTENT));  
//        pic.setAdjustViewBounds(true);  
//        pic.setScaleType(ScaleType.FIT_XY);  
//        pic.setMaxHeight(250);  
//        pic.setMaxWidth(250);  
//        LinearLayout ll = new LinearLayout(this);  
//        ll.setOrientation(LinearLayout.VERTICAL);  
//        ll.setLayoutParams(new LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.MATCH_PARENT));  
//        ll.setGravity(Gravity.CENTER);  
//        ll.addView(label);  
//        ll.addView(pic);  
//        setContentView((View)ll);
//    }
//
//}
//
//class AXplorienceView extends View {
//    private Bitmap mBitmap;
//    private long mStartTime;
//
//    /* implementend by libplasma.so */
//    private static native void renderPlasma(Bitmap  bitmap, long time_ms);
//
//    public AXplorienceView(Context context) {
//        super(context);
//
//        final int W = 200;
//        final int H = 200;
//
//        mBitmap = Bitmap.createBitmap(W, H, Bitmap.Config.RGB_565);
//        mStartTime = System.currentTimeMillis();
//    }
//
//    @Override protected void onDraw(Canvas canvas) {
//        //canvas.drawColor(0xFFCCCCCC);
//        renderPlasma(mBitmap, System.currentTimeMillis() - mStartTime);
//        canvas.drawBitmap(mBitmap, 0, 0, null);
//        // force a redraw, with a different time-based pattern.
//        invalidate();
//    }
//}
