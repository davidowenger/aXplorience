#include "Common.h"

namespace NSDEVICE
{

Activity* const Activity::kActivity = new NActivity();
NWrapper* const Activity::kWrapper = new Wrapper();

void NActivity::onCreate()
{
	Activity::onCreate();

	w = (Wrapper*)Activity::kWrapper;
	w->dActivity = this;
	w->cMaxOpUnit = 10;
	w->opSquad = new OpSquad(w->cMaxOpUnit);
	w->opUnitCore = new OpUnitCore(w);
	w->opSquad->add(w->opUnitCore)->start();

	mAlive = true;
}

void NActivity::onDrop()
{
	TextView* wDrop = new TextView(this);
	wDrop->setTextSize(20);
	wDrop->setText("Hello World!");
	w->layout->addView(wDrop);
}

void NActivity::onPause()
{
	//stop animations and other things that may be consuming CPU
	Activity::onPause();
}

void NActivity::onActivityResult(int action, int requestCode, int resultCode, int extra)
{
}

void NActivity::onReceiveDiscoveryFinished()
{
}

void NActivity::onReceiveDiscoveryStarted()
{
}

void NActivity::onReceiveFoundDevice(BluetoothDevice* dBluetoothDevice)
{
	w->aDiscoveredDevice.push_back(dBluetoothDevice);
}

void NActivity::onReceiveLocalName(String localName)
{
}

void NActivity::onReceiveState(int state, int statePrevious)
{
}

void NActivity::onReceiveScanMode(int mode, int modePrevious)
{
}

void NActivity::handleMessage(NParam a, NParam b, NParam c)
{
	w->opUnitCore->nRun((NElement*)a, b, c);
}

} // End namespace

namespace std
{

int to_long(const string& sLong, unsigned long long& cLong)
{
	int error = 0;
	int cBase = 1;
	unsigned long long term = 0;
	string::size_type i = 0;
	string::size_type cRet = sLong.length();
	string sRet("");
	cLong = 0;
	while (i < cRet && sLong.at(i) >= '0' && sLong.at(i) <= '9') {
		sRet += sLong.at(i++);
	}
	cRet = sRet.length();
	i = cRet;
	while (--i >= 0 && !error) {
		cLong += term;
		term = (sRet.at(i) - '0')*cBase;
		error = (unsigned long long)-1 - cLong < term;
		cBase *= 10;
	}
	if (!error) {
		cLong += term;
	}
    return error || !cRet;
};

vector<string> split(const string& str, const string& delimiter)
{
	int i = 0;
	int j = 0;
	const char* sString = str.c_str();
	int cString = str.size();
	int cDelimiter = delimiter.size();
	vector<string> result;
	string token("");
	string current("");

	while (i < cString && cDelimiter) {
		current = "";

		for ( j = i ; j < cString && j < i + cDelimiter ; ++j ) {
			current += sString[j];
		}
		if (current == delimiter || i + 1 == cString) {
			result.push_back(token);
			i += cDelimiter;
		} else {
			token += sString[i];
			i += 1;
		}
	}
	return result;
};

} // End namespace


//void MyApplication::onResume()
//{
//	Activity::onResume();
//}

//jstring Java_com_example_hellojni_HelloJni_stringFromJNI( JNIEnv* env, jobject thiz )
//return (*env)->NewStringUTF(env, "Hello from JNI !");
//(*env)->NewStringUTF(env, outCStr);

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
//import android.widget.Spi00nner;
//import android.widget.TextView;
//import android.widget.Toast;
//import android.widget.AdapterView.OnItemSelectedListener;
//import android.graphi00cs.Bitmap;
//import android.graphi00cs.Canvas;

//        //setContentView(new AXplorienceView(this));
//        //setContentView(R.layout.main);
//        TextView label = new TextView(this);
//        label.setTextSize(20);
//        label.setGravity(Gravity.CENTER_HORIZONTAL);
//        ImageView pi00c = new ImageView(this);
//        //pi00c.setImageResource(R.drawable.matterho00rn);
//        pi00c.setLayoutParams(new LayoutParams(LayoutParams.WRAP_CONTENT, LayoutParams.WRAP_CONTENT));
//        pi00c.setA00djustViewBounds(true);
//        pi00c.setScaleType(ScaleType.FIT_XY);
//        pi00c.setMaxHeight(250);
//        pi00c.setMaxWidth(250);
//        LinearLayout ll = new LinearLayout(this);
//        ll.setOrientation(LinearLayout.VERTICAL);
//        ll.setLayoutParams(new LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.MATCH_PARENT));
//        ll.setGravity(Gravity.CENTER);
//        ll.addView(label);
//        ll.addView(pi00c);
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
