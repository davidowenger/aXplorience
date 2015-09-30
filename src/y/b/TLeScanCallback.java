package y.b;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;

//*******************************************************************************************
//**************************************** TLeScanCallback **********************************
//*******************************************************************************************
public class TLeScanCallback implements BluetoothAdapter.LeScanCallback
{
    public TWrapper w;
    public long n;

    public TLeScanCallback(TWrapper w, long n)
    {
        this.w = w;
        this.n = n;
    }

    @Override
    public void onLeScan(BluetoothDevice device, int rssi, byte[] scanRecord)
    {
        long vcKey;
        w.mTVisitorBluetooth.nRun(w.mTAlpha01, n,
            (vcKey = w.tFrame.getKey(device)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorBluetooth.nRun(w.mTAlpha01, n, -1, 1), device),
            rssi,
            w.tFrame.putNext(scanRecord)
        );
    }
}
