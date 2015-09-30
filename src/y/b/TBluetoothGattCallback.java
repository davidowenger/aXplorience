package y.b;

import android.bluetooth.BluetoothGatt;
import android.bluetooth.BluetoothGattCharacteristic;
import android.bluetooth.BluetoothGattCallback;

//*******************************************************************************************
//**************************************** TBluetoothGattCallback ***************************
//*******************************************************************************************
public class TBluetoothGattCallback extends BluetoothGattCallback
{
    public TWrapper w;
    public long n;

    public TBluetoothGattCallback(TWrapper w, long n)
    {
        this.w = w;
        this.n = n;
    }

    @Override
    public void onCharacteristicWrite(BluetoothGatt gatt, BluetoothGattCharacteristic characteristic, int status)
    {
        long vcKey;
        w.mTVisitorBluetoothGatt.nRun(w.mTAlpha01, n,
            (vcKey = w.tFrame.getKey(gatt)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorBluetoothGatt.nRun(w.mTAlpha01, n, -1, 2), gatt),
            (vcKey = w.tFrame.getKey(characteristic)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorBluetoothGatt.nRun(w.mTAlpha01, n, -1, 1), characteristic),
            status
        );
    }

    @Override
    public void onConnectionStateChange(BluetoothGatt gatt, int status, int newState)
    {
        long vcKey;
        w.mTVisitorBluetoothGatt.nRun(w.mTBeta01, n,
            (vcKey = w.tFrame.getKey(gatt)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorBluetoothGatt.nRun(w.mTBeta01, n, -1, 1), gatt),
            status,
            newState
        );
    }

    @Override
    public void onServicesDiscovered(BluetoothGatt gatt, int status)
    {
        long vcKey;
        w.mTVisitorBluetoothGatt.nRun(w.mTGamma01, n,
            (vcKey = w.tFrame.getKey(gatt)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorBluetoothGatt.nRun(w.mTGamma01, n, -1, 1), gatt),
            status
        );
    }
}
