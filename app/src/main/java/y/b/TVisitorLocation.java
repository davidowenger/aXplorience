package y.b;

import android.content.Intent;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.location.LocationProvider;
import android.os.Looper;
import android.provider.Settings;

public class TVisitorLocation extends TKrossVisitor
{
    public TVisitorLocation(TWrapper w) {
        super(w);
    }

    //*******************************************************************************
    //******************************* Location **************************************
    //*******************************************************************************
    // float getAccuracy()
    public long visit(TAlpha00 element, long a, long b, long c, long d, long e)
    {
        return Double.doubleToRawLongBits(((Location)w.sObject.get(a)).getAccuracy());
    }

    // double getAltitude()
    public long visit(TBeta00 element, long a, long b, long c, long d, long e)
    {
        return Double.doubleToRawLongBits(((Location)w.sObject.get(a)).getAltitude());
    }

    // double getLatitude()
    public long visit(TGamma00 element, long a, long b, long c, long d, long e)
    {
        return Double.doubleToRawLongBits(((Location)w.sObject.get(a)).getLatitude());
    }

    // double getLongitude()
    public long visit(TDelta00 element, long a, long b, long c, long d, long e)
    {
        return Double.doubleToRawLongBits(((Location)w.sObject.get(a)).getLongitude());
    }

    // long long int getTime()
    public long visit(TEpsilon00 element, long a, long b, long c, long d, long e)
    {
        return ((Location)w.sObject.get(a)).getTime();
    }

    // bool hasAltitude()
    public long visit(TDzeta00 element, long a, long b, long c, long d, long e)
    {
        return ( ((Location)w.sObject.get(a)).hasAltitude() ? 1 : 0 );
    }

    //*******************************************************************************
    //**************************** LocationListener *********************************
    //*******************************************************************************
    // LocationListener()
    public long visit(TEta00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new TLocationListener(w, a));
        return 0;
    }

    //*******************************************************************************
    //***************************** LocationManager *********************************
    //*******************************************************************************
    // vector<String> getAllProviders()
    public long visit(TTheta00 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.putNext(((LocationManager)w.sObject.get(a)).getAllProviders());
    }

    // Location* getLastKnownLocation(const String& provider)
    public long visit(TIota00 element, long a, long b, long c, long d, long e)
    {
        Location vLocation = null;

        try {
            vLocation = ((LocationManager)w.sObject.get(a)).getLastKnownLocation((String)w.mTKrossSystem.nRunObject(c));
        }
        catch (Exception vException) {
            if (w.doDebug) vException.printStackTrace();
            vLocation = null;
        }
        return w.mTKrossSystem.emplaceKey(b, vLocation);
    }

    // LocationProvider* getProvider(const String& name)
    public long visit(TTau00 element, long a, long b, long c, long d, long e)
    {
        LocationProvider vLocationProvider = null;

        try {
            vLocationProvider = ((LocationManager)w.sObject.get(a)).getProvider((String)w.mTKrossSystem.nRunObject(c));
        }
        catch (Exception vException) {
            if (w.doDebug) vException.printStackTrace();
            vLocationProvider = null;
        }
        return w.mTKrossSystem.emplaceKey(b, vLocationProvider);
    }

    // bool isProviderEnabled(const String& provider)
    public long visit(TKappa00 element, long a, long b, long c, long d, long e)
    {
        boolean vResult = false;

        try {
            vResult = ((LocationManager)w.sObject.get(a)).isProviderEnabled((String)w.mTKrossSystem.nRunObject(b));
        }
        catch (Exception vException) {
            if (w.doDebug) vException.printStackTrace();
            vResult = false;
        }
        return ( vResult ? 1 : 0 );
    }

    // void removeUpdates(LocationListener* listener)
    public long visit(TLambda00 element, long a, long b, long c, long d, long e)
    {
        try {
            ((LocationManager)w.sObject.get(a)).removeUpdates(w.mTKrossSystem.getValue(b, LocationListener.class));
        }
        catch (Exception vException) {
            if (w.doDebug) vException.printStackTrace();
        }
        return 0;
    }

    // void requestLocationUpdates(String provider, long long int minTime, float minDistance, LocationListener* listener, Looper* looper)
    public long visit(TMu00 element, long a, long b, long c, long d, long e)
    {
        long minTime = c>>32;
        int vcInt = (int)(c&0xFFFFFFFF);
        float minDistance = Float.intBitsToFloat(vcInt);

        try {
            ((LocationManager)w.sObject.get(a)).requestLocationUpdates((String)w.mTKrossSystem.nRunObject(b), minTime, minDistance, w.mTKrossSystem.getValue(d, LocationListener.class), w.mTKrossSystem.getValue(e, Looper.class));
        }
        catch (Exception vException) {
            if (w.doDebug) vException.printStackTrace();
        }
        return 0;
    }

    // void requestSingleUpdate(String provider, LocationListener* listener, Looper* looper)
    public long visit(TNu00 element, long a, long b, long c, long d, long e)
    {
        try {
            ((LocationManager)w.sObject.get(a)).requestSingleUpdate((String)w.mTKrossSystem.nRunObject(b), w.mTKrossSystem.getValue(c, LocationListener.class), w.mTKrossSystem.getValue(d, Looper.class));
        }
        catch (Exception vException) {
            if (w.doDebug) vException.printStackTrace();
        }
        return 0;
    }

    //void enable()
    public long visit(TSigma00 element, long a, long b, long c, long d, long e)
    {
        Intent intent = new Intent(Settings.ACTION_LOCATION_SOURCE_SETTINGS);
        w.tActivity.startActivity(intent);
        return 0;
    }

    //*******************************************************************************
    //********************************** LocationProvider ***************************
    //*******************************************************************************
    // bool hasMonetaryCost()
    public long visit(TXi00 element, long a, long b, long c, long d, long e)
    {
        return (((LocationProvider)w.sObject.get(a)).hasMonetaryCost() ? 1 : 0 );
    }

    // bool supportsAltitude()
    public long visit(TOmicron00 element, long a, long b, long c, long d, long e)
    {
        return (((LocationProvider)w.sObject.get(a)).supportsAltitude() ? 1 : 0 );
    }

    // bool supportsSpeed()
    public long visit(TPi00 element, long a, long b, long c, long d, long e)
    {
        return (((LocationProvider)w.sObject.get(a)).supportsSpeed() ? 1 : 0 );
    }

    // bool supportsBearing()
    public long visit(TRho00 element, long a, long b, long c, long d, long e)
    {
        return (((LocationProvider)w.sObject.get(a)).supportsBearing() ? 1 : 0 );
    }
}
