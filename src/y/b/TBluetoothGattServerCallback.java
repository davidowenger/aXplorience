package y.b;

import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothGattService;
import android.bluetooth.BluetoothGattCharacteristic;
import android.bluetooth.BluetoothGattServerCallback;

//*******************************************************************************************
//********************************** TBluetoothGattServerCallback ***************************
//*******************************************************************************************
public class TBluetoothGattServerCallback extends BluetoothGattServerCallback
{
    public TWrapper w;
    public long n;

    public TBluetoothGattServerCallback(TWrapper w, long n)
    {
        this.w = w;
        this.n = n;
    }

    @Override
    public void onCharacteristicWriteRequest(
        BluetoothDevice device,
        int requestId,
        BluetoothGattCharacteristic characteristic,
        boolean preparedWrite,
        boolean responseNeeded,
        int offset,
        byte[] value
    ) {
        long vcKey;
        w.mTVisitorBluetoothGatt.nRun(w.mTDelta01, n,
            ( vcKey = w.tFrame.getKey(device)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorBluetoothGatt.nRun(w.mTDelta01, n, -1, 2), device ),
            ( vcKey = w.tFrame.getKey(characteristic)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorBluetoothGatt.nRun(w.mTDelta01, n, -1, 1), characteristic ),
            w.tFrame.putNext(value),
            requestId << 32 + offset << 2 + ( preparedWrite ? 2 : 0 ) + ( responseNeeded ? 1 : 0 )
        );
    }

    @Override
    public void onConnectionStateChange (BluetoothDevice device, int status, int newState)
    {
        long vcKey;
        w.mTVisitorBluetoothGatt.nRun(w.mTEpsilon01, n,
            (vcKey = w.tFrame.getKey(device)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorBluetoothGatt.nRun(w.mTEpsilon01, n, -1, 1), device),
            status,
            newState
        );
    }

    // API 21
    public void onNotificationSent(BluetoothDevice device, int status)
    {
        long vcKey;
        w.mTVisitorBluetoothGatt.nRun(w.mTDzeta01, n,
            (vcKey = w.tFrame.getKey(device)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorBluetoothGatt.nRun(w.mTDzeta01, n, -1, 1), device),
            status
        );
    }

    @Override
    public void onServiceAdded(int status, BluetoothGattService service)
    {
        long vcKey;
        w.mTVisitorBluetoothGatt.nRun(w.mTEta01, n,
            status,
            (vcKey = w.tFrame.getKey(service)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorBluetoothGatt.nRun(w.mTEta01, n, -1, 1), service)
        );
    }
}
