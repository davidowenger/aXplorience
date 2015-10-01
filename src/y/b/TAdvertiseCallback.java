package y.b;

import android.bluetooth.le.AdvertiseCallback;
import android.bluetooth.le.AdvertiseSettings;

//*******************************************************************************************
//**************************************** TAdvertiseCallback *******************************
//*******************************************************************************************
public class TAdvertiseCallback extends AdvertiseCallback
{
    public TWrapper w;
    public long n;

    public TAdvertiseCallback(TWrapper w, long n)
    {
        this.w = w;
        this.n = n;
    }

    @Override
    public void onStartSuccess(AdvertiseSettings settingsInEffect)
    {
        long vcKey;
        w.mTVisitorBluetoothLe.nRun(w.mTAlpha02, n,
            (vcKey = w.tFrame.getKey(settingsInEffect)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorBluetoothLe.nRun(w.mTAlpha02, n, -1, 1), settingsInEffect)
        );
    }

    @Override
    public void onStartFailure(int errorCode)
    {
        w.mTVisitorBluetoothLe.nRun(w.mTBeta02, n,
            errorCode
        );
    }
}
