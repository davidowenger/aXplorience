package y.b;

import java.util.List;

import android.bluetooth.le.ScanCallback;
import android.bluetooth.le.ScanResult;

//*******************************************************************************************
//**************************************** TScanCallback ***************************
//*******************************************************************************************
public class TScanCallback extends ScanCallback
{
    public TWrapper w;
    public long n;

    public TScanCallback(TWrapper w, long n)
    {
        this.w = w;
        this.n = n;
    }

    @Override
    public void onBatchScanResults(List<ScanResult> results)
    {
        w.mTVisitorBluetoothGatt.nRun(w.mTGamma02, n,
            w.tFrame.putNext(results)
        );
    }

    @Override
    public void onScanFailed(int errorCode)
    {
        w.mTVisitorBluetoothGatt.nRun(w.mTDelta02, n,
            errorCode
        );
    }

    @Override
    public void onScanResult(int callbackType, ScanResult result)
    {
        long vcKey;
        w.mTVisitorBluetoothGatt.nRun(w.mTEpsilon02, n,
            callbackType,
            (vcKey = w.tFrame.getKey(result)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorBluetoothLe.nRun(w.mTEpsilon02, n, -1, 1), result)
        );
    }
}
