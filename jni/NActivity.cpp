#include "Common.h"

namespace NSDEVICE
{

Activity* Activity::getInstance(NWrapper* const vNWrapper)
{
    Wrapper* vWrapper = new Wrapper();
    vWrapper->w = vNWrapper;
	return new NActivity(vWrapper);
}

NActivity::NActivity(Wrapper* vWrapper)
    : Activity(), OpUnit(vWrapper)
{
}

NActivity::~NActivity()
{
}

void NActivity::onCreate()
{
	Activity::onCreate();

	//todo
	mWrapper->sFileDir = w->nFrame->tGetString(w->nFrame->tRunObject(1));

	mWrapper->dBluetoothAdapter = new BluetoothAdapter();
	mWrapper->layout = new LinearLayout(this);
	setContentView((View*)mWrapper->layout);

    //mWrapper->aDiscoveredDevice = new Col<BluetoothDevice*>();
	mWrapper->cMaxOpUnit = 25;
	mWrapper->opSquad = new OpSquad(mWrapper, mWrapper->cMaxOpUnit);
	mWrapper->opUnitCore = new OpUnitCore(mWrapper);

    mWrapper->opSquad->add(this);
    mWrapper->opSquad->add(mWrapper->opUnitCore)->start();
}

void NActivity::onPause()
{
    //stop animations and other things that may be consuming CPU
    Activity::onPause();
}

void NActivity::onStop()
{
    //stop animations and other things that may be consuming CPU
    delete mWrapper->opSquad;
    Activity::onStop();
}

void NActivity::handleMessage(NParam a, NParam b, NParam c)
{
    nRun((NElement*)a, b, c);
}

// Display a Drop from a peer
NReturn NActivity::visit(NAlpha01* element, NParam a, NParam b, NParam c, NParam d)
{
    DBObject* vDBObject = ((DBObject*)a);
    TextView* vTextView = new TextView(this);
    vTextView->setTextSize(20);
    vTextView->setText(vDBObject->get("title"));
    mWrapper->layout->addView(vTextView);
    return 0;
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
    sendOp(mWrapper->opUnitCore->mId, mWrapper->w->mNAlpha00, new OpParam((NParam)dBluetoothDevice));
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
	long j = cRet;
	while (--j >= 0 && !error) {
		cLong += term;
		term = (sRet.at(j ) - '0')*cBase;
		error = (unsigned long long)-1 - cLong < term;
		cBase *= 10;
	}
	if (!error) {
		cLong += term;
	}
    return error || !cRet;
}

vector<string> split(const string& str, const string& delimiter)
{
    //FIXME: UTF8 compatibility
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
}

int utf8len(const string& vString)
{
	int ret = 0;
	const char* c = vString.c_str();
	while (*c) ret += (*c++ & 0xc0) != 0x80;
	return ret;
}

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
