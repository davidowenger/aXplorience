package y.b;

import android.location.Location;
import android.location.LocationListener;
import android.os.Bundle;

//*******************************************************************************************
//************************************ LocationListener *************************************
//*******************************************************************************************
public class TLocationListener implements LocationListener
{
    public TWrapper w;
    public long n;

    public TLocationListener(TWrapper w, long n)
    {
        this.w = w;
        this.n = n;
    }

    @Override
    public void onLocationChanged(Location location)
    {
        long vcKey;
        w.mTVisitorLocation.nRun(w.mTAlpha00, n,
            (vcKey = w.mTKrossSystem.getKey(location)) != -1 ? vcKey : w.mTKrossSystem.putKey(w.mTVisitorLocation.nRun(w.mTAlpha00, n, -1, 1), location)
        );
    }

    @Override
    public void onProviderDisabled(String provider)
    {
        w.mTVisitorLocation.nRun(w.mTBeta00, n,
            w.mTKrossSystem.putNext(provider)
        );
    }

    @Override
    public void onProviderEnabled(String provider)
    {
        w.mTVisitorLocation.nRun(w.mTGamma00, n,
            w.mTKrossSystem.putNext(provider)
        );
    }

    @Override
    public void onStatusChanged(String provider, int status, Bundle extras)
    {
        long vcKey;
        w.mTVisitorLocation.nRun(w.mTDelta00, n,
            w.mTKrossSystem.putNext(provider),
            status,
            (vcKey = w.mTKrossSystem.getKey(extras)) != -1 ? vcKey : w.mTKrossSystem.putKey(w.mTVisitorLocation.nRun(w.mTDelta00, n, -1, 1), extras)
        );
    }
}
