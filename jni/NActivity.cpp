#include "Common.h"
#include "Theme.h"

namespace NSDEVICE
{

Activity* Activity::getInstance(NWrapper* const vNWrapper)
{
    Wrapper* vWrapper = new Wrapper();
    vWrapper->w = vNWrapper;
	return new NActivity(vWrapper);
}

NActivity::NActivity(Wrapper* vWrapper)
    : Activity(), OpUnit(vWrapper), mcView(0), mState(7)
{
}

NActivity::~NActivity()
{
    //TODO: delete widgets
    delete mWrapper;
}

void NActivity::onCreate(Bundle* savedInstanceState)
{
    nuint i;

    Activity::onCreate(savedInstanceState);

    mWrapper->mNActivity = this;
    mWrapper->mApplication = getApplication();
    mWrapper->mFragmentManager = getFragmentManager();
    mWrapper->mResources = mWrapper->mApplication->getResources();
    mWrapper->mDisplayMetrics = mWrapper->mResources->getDisplayMetrics();
    mWrapper->mConfiguration = mWrapper->mResources->getConfiguration();
    mWrapper->mcDensity = mWrapper->mDisplayMetrics->getDensity();
    mWrapper->mcWidthDp = mWrapper->mConfiguration->getScreenWidthDp();
    mWrapper->maColor = new nuint[25] {
        0x00FFFFFF, //transparent
        0xFF000000, //black
        0xFFFFFFFF, //white
        0xFFE8E8E8, //grey 1
        0x75E8E8E8, //grey 2
        0x50E8E8E8, //grey
        0xFFFFE4E4, //red 1
        0xFFFFCACA, //red 2
        0xFFCC0000, //red
        0xFFF0F8DB, //green 1
        0xFFE2F0B6, //green 2 // 10
        0xFF669900, //green
        0xFFE2F4FB, //blue 1
        0xFFC5EAF8, //blue 2
        0xFF0099CC, //blue
        0xFFFFF6DF, //yellow 1
        0xFFFFECC0, //yellow 2
        0xFFFF8A00, //yellow
        0xFFF5EAFA, //purple 1
        0xFFE5CAF2, //purple 2
        0xFF9933CC, //purple  // 20
        0xFFFFEED5, //orange 1
        0xFFFF8F76, //orange 2
        0xFFFF4E00, //orange
        0xFF99CC00, //green selected
    };
    mWrapper->mcRootLayoutItem = 9;
    mWrapper->maRootLayoutItem = new RootLayoutItem[mWrapper->mcRootLayoutItem];
    mWrapper->maRootLayoutItem[Wrapper::kViewNone] =     {0, {{0,0,0}, {0,0,0}, {0,0,0}}};
    mWrapper->maRootLayoutItem[Wrapper::kViewHome] =     {0, {{0,0,2}, {0,0,0}, {0,0,0}}};
    mWrapper->maRootLayoutItem[Wrapper::kViewAbout] =    {1, {{0,0,1}, {1,1,2}, {0,0,0}}};
    mWrapper->maRootLayoutItem[Wrapper::kViewSettings] = {1, {{0,0,1}, {2,0,2}, {0,0,0}}};
    mWrapper->maRootLayoutItem[Wrapper::kViewDetails] =  {1, {{0,0,2}, {3,1,2}, {0,0,0}}};
    mWrapper->maRootLayoutItem[Wrapper::kViewEdit] =     {2, {{0,0,2}, {3,1,2}, {4,1,2}}};
    mWrapper->maRootLayoutItem[Wrapper::kViewAdd] =      {1, {{0,0,2}, {4,1,2}, {0,0,0}}};
    mWrapper->maRootLayoutItem[Wrapper::kViewDelete] =   {0, {{0,0,2}, {0,0,0}, {0,0,0}}};
    mWrapper->maRootLayoutItem[Wrapper::kViewSave] =     {1, {{0,0,2}, {3,1,2}, {0,0,0}}};

    mWrapper->mRootLayoutId = 0x001FF100;
    mWrapper->mRootLayout = new RootLayout(mWrapper);
    mWrapper->mRootLayout->setId(mWrapper->mRootLayoutId);
    setContentView((View*)mWrapper->mRootLayout);

	//todo
	mWrapper->sFileDir = mWrapper->w->nFrame->tGetString(mWrapper->w->nFrame->tRunObject(1));

    mWrapper->maDrawable = new Drawable*[12] {
		mWrapper->mResources->getDrawable("ic_visibility_grey"),
		mWrapper->mResources->getDrawable("ic_visibility_green"),
		mWrapper->mResources->getDrawable("ic_visibility_black_48dp"),
		mWrapper->mResources->getDrawable("ic_left_black"),
		mWrapper->mResources->getDrawable("ic_left_green"),
		mWrapper->mResources->getDrawable("ic_right_black"),
		mWrapper->mResources->getDrawable("ic_right_green"),
		mWrapper->mResources->getDrawable("ic_action_edit"),
		mWrapper->mResources->getDrawable("ic_action_delete"),
		mWrapper->mResources->getDrawable("ic_action_save"),
        mWrapper->mResources->getDrawable("ic_action_add"),
        mWrapper->mResources->getDrawable("ic_launcher"),
	};
    mWrapper->mcTextSize = (int)(27/mWrapper->mcDensity);
	mWrapper->maMenu = new String[3] {
        "Home",
        "Settings",
        "About"
	};
	mWrapper->mcCategory = 4;
	mWrapper->maCategory = new String[mWrapper->mcCategory] {
		"Listen to Music",
		"Have a Drink",
		"Play some Game",
		"See some Event"
	};

    mWrapper->mActionBar = getActionBar();
    mWrapper->mActionBar->setIcon(mWrapper->maDrawable[11]);
    mWrapper->mMessageLayout = new LinearLayout(mWrapper->mApplication);
    mWrapper->mWidgetHome = new WidgetHome(mWrapper);

    mWrapper->mcFragmentView = 5;
    mWrapper->maGestureDetector = new GestureDetector*[mWrapper->mcFragmentView];
    mWrapper->maFragmentView = new FragmentView*[mWrapper->mcFragmentView] {
        (mWrapper->mFragmentViewHome = new FragmentViewHome(mWrapper)),
        (mWrapper->mFragmentViewAbout = new FragmentViewAbout(mWrapper)),
        (mWrapper->mFragmentViewSettings = new FragmentViewSettings(mWrapper)),
        (mWrapper->mFragmentViewDetails = new FragmentViewDetails(mWrapper)),
        (mWrapper->mFragmentViewEdit = new FragmentViewEdit(mWrapper))
    };
    for (i = 0 ; i < mWrapper->mcFragmentView ; ++i) {
        mWrapper->maGestureDetector[i] = new GestureDetector(mWrapper->mApplication, mWrapper->maFragmentView[i]);
    };
    mWrapper->mcFragmentLevel = 3;
    mWrapper->maFragmentLevel = new FragmentLevel*[mWrapper->mcFragmentLevel] {
        (mWrapper->mFragmentLevel0 = new FragmentLevel0(mWrapper)),
        (mWrapper->mFragmentLevel1 = new FragmentLevel1(mWrapper)),
        (mWrapper->mFragmentLevel2 = new FragmentLevel2(mWrapper))
    };

	mWrapper->cMaxOpUnit = 18;
	mWrapper->opSquad = new OpSquad(mWrapper, mWrapper->cMaxOpUnit);
	mWrapper->opUnitCore = new OpUnitCore(mWrapper);

    mWrapper->opSquad->add(this);
    mWrapper->opSquad->add(mWrapper->opUnitCore)->start();
}

void NActivity::onStart()
{
    Activity::onStart();
}

void NActivity::onPause()
{
    //stop animations and other things that may be consuming CPU
    Activity::onPause();
}

void NActivity::onStop()
{
    Activity::onStop();
}

void NActivity::onDestroy()
{
    //FIXME check
    delete mWrapper->opSquad;
    delete mWrapper->mRootLayout;
    Activity::onDestroy();
}

void NActivity::buzz(DBCollection* vDBCollection)
{
    render(vDBCollection);
    sendOp(0, mWrapper->opUnitCore->mId, mWrapper->w->mNMu00, new Op());
}

void NActivity::clear(DBCollection* vDBCollection)
{
    int i = 0;
    vector<WidgetMessage*> vaWidgetMessage;

    for (i = 0 ; i < mWrapper->mMessageLayout->getChildCount() ; ++i) {
        vaWidgetMessage.push_back((WidgetMessage*)mWrapper->mMessageLayout->getChildAt(i));
    }
    mWrapper->mMessageLayout->removeAllViews();

    for (WidgetMessage* vWidgetMessage : vaWidgetMessage) {
         delete vWidgetMessage;
    }
    for (i = 0 ; i < vDBCollection->count() ; ++i) {
        mWrapper->mMessageLayout->addView( vDBCollection->get(i)->get("in") == mWrapper->dbh->TRUE ? (View*)new WidgetMessageInbound(mWrapper) : (View*)new WidgetMessageOutbound(mWrapper) );
    }
    render(vDBCollection);
}

void NActivity::handleMessage(NParam a, NParam b, NParam c, NParam d)
{
    nRun((NElement*)a, b, c, d);
}

void NActivity::onReceiveFoundDevice(BluetoothDevice* dBluetoothDevice)
{
    sendOp(0, mWrapper->opUnitCore->mId, mWrapper->w->mNAlpha00, new OpParam((NParam)dBluetoothDevice));
}

void NActivity::render(DBCollection* vDBCollection)
{
    int i = 0;

    for (i = 0 ; i < vDBCollection->count() ; ++i) {
        ((WidgetMessage*)mWrapper->mMessageLayout->getChildAt(i))->init(0, to_long(vDBCollection->get(i)->get("id")));
    }
    delete vDBCollection;
}

bool NActivity::setView(nint vcView, nint vcDBObjectId)
{
    nuint i;
    bool ret = true;

    for (i = 0 ; i < mWrapper->mcFragmentLevel ; ++i) {
        mWrapper->maFragmentLevel[i]->init(vcView, vcDBObjectId);
    }
    mcView = vcView;
    return ret;
}

void NActivity::tilt(nuint color)
{
    mWrapper->maFragmentView[0]->setBackgroundColor(color);
    mWrapper->maFragmentView[0]->invalidate();
    mState = color;
}

NReturn NActivity::visit(NAlpha01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    buzz((DBCollection*)a);
    return 0;
}

NReturn NActivity::visit(NBeta01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    clear((DBCollection*)a);
    return 0;
}

NReturn NActivity::visit(NGamma01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    render((DBCollection*)a);
    return 0;
}

NReturn NActivity::visit(NDelta01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    setView((nint)a, (nint)b);
    return 0;
}

NReturn NActivity::visit(NEpsilon01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    tilt((nuint)a);
    return 0;
}

} // End namespace

namespace std
{

long long int to_long(const string& vsLong, int* vcError)
{
	long long int vcRet = 0;
	istringstream vistringstream(vsLong);
	vistringstream >> vcRet;
    int vcErrorInternal = vsLong.empty() || vistringstream.fail();

    if (vcError) {
    	*vcError = vcErrorInternal;
    }
    return ( vcErrorInternal ? 0 : vcRet );
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
		if (current == delimiter) {
			result.push_back(token);
			token = "";
			i += cDelimiter;
		} else {
			token += sString[i];
			i += 1;
		}
	}
    result.push_back(token);
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
