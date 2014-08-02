#ifndef __MYAPPLICATION_H__
#define __MYAPPLICATION_H__

namespace NNSUser
{

class MyApplication : public Activity
{
protected:
	void onCreate(Bundle* savedInstanceState);
	void onPause();
};

} // End namespace

#endif
