package y.b;

import java.util.ArrayList;
import java.util.List;

import android.bluetooth.BluetoothDevice;
import android.bluetooth.le.AdvertiseCallback;
import android.bluetooth.le.AdvertiseData;
import android.bluetooth.le.AdvertiseSettings;
import android.bluetooth.le.BluetoothLeAdvertiser;
import android.bluetooth.le.BluetoothLeScanner;
import android.bluetooth.le.ScanCallback;
import android.bluetooth.le.ScanRecord;
import android.bluetooth.le.ScanResult;

import android.os.ParcelUuid;

public class TVisitorBluetoothLe extends TKrossVisitor
{
    public TVisitorBluetoothLe(TWrapper w) {
        super(w);
    }

    //*******************************************************************************
    //********************************* AdvertiseCallback ***************************
    //*******************************************************************************
    //AdvertiseCallback()
    public long visit(TAlpha00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new TAdvertiseCallback(w, a));
        return 0;
    }

    //*******************************************************************************
    //********************************* AdvertiseData *******************************
    //*******************************************************************************
    //NArray<String> getServiceUuids()
    public long visit(TBeta00 element, long a, long b, long c, long d, long e)
    {
        List<String> vaString = new ArrayList<String>();
        List<ParcelUuid> vaParcelUuid = ((AdvertiseData)w.sObject.get(a)).getServiceUuids();

        for (ParcelUuid vParcelUuid : vaParcelUuid) {
            vaString.add(vParcelUuid.toString());
        }
        return w.mTKrossSystem.putNext(vaString);
    }

    //*******************************************************************************
    //********************************* AdvertiseData.Builder ***********************
    //*******************************************************************************
    //Builder()
    public long visit(TSigma00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new AdvertiseData.Builder());
        return 0;
    }

    //AdvertiseData::Builder* addServiceUuid(const String& serviceUuid)
    public long visit(TTau00 element, long a, long b, long c, long d, long e)
    {
        ((AdvertiseData.Builder)w.sObject.get(a)).addServiceUuid(ParcelUuid.fromString((String)w.mTKrossSystem.nRunObject(b)));
        return 0;
    }

    //AdvertiseData* build()
    public long visit(TUpsilon00 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.emplaceKey(b, ((AdvertiseData.Builder)w.sObject.get(a)).build());
    }

    //*******************************************************************************
    //*************************** AdvertiseSettings *********************************
    //*******************************************************************************

    //int getMode()
    public long visit(TGamma00 element, long a, long b, long c, long d, long e)
    {
        return ((AdvertiseSettings)w.sObject.get(a)).getMode();
    }

    //int getTimeout()
    public long visit(TDelta00 element, long a, long b, long c, long d, long e)
    {
        return ((AdvertiseSettings)w.sObject.get(a)).getTimeout();
    }

    //bool isConnectable()
    public long visit(TEpsilon00 element, long a, long b, long c, long d, long e)
    {
        return ( ((AdvertiseSettings)w.sObject.get(a)).isConnectable() ? 1 : 0 );
    }

    //*******************************************************************************
    //*************************** AdvertiseSettings.Builder *************************
    //*******************************************************************************
    //Builder()
    public long visit(TPhi00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new AdvertiseSettings.Builder());
        return 0;
    }

    //AdvertiseSettings* build()
    public long visit(TAlpha01 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.emplaceKey(b, ((AdvertiseSettings.Builder)w.sObject.get(a)).build());
    }

    //AdvertiseSettings::Builder* setConnectable(bool connectable)
    public long visit(TKhi00 element, long a, long b, long c, long d, long e)
    {
        ((AdvertiseSettings.Builder)w.sObject.get(a)).setConnectable(b != 0);
        return 0;
    }

    //AdvertiseSettings::Builder* setTimeout(int timeoutMillis)
    public long visit(TPsi00 element, long a, long b, long c, long d, long e)
    {
        ((AdvertiseSettings.Builder)w.sObject.get(a)).setTimeout((int)b);
        return 0;
    }

    //AdvertiseSettings::Builder* setTxPowerLevel(int txPowerLevel)
    public long visit(TOmega00 element, long a, long b, long c, long d, long e)
    {
        ((AdvertiseSettings.Builder)w.sObject.get(a)).setTxPowerLevel((int)b);
        return 0;
    }

    //*******************************************************************************
    //*************************** BluetoothLeAdvertiser *****************************
    //*******************************************************************************

    //void startAdvertising(AdvertiseSettings* settings, AdvertiseData* advertiseData, AdvertiseCallback* callback)
    public long visit(TDzeta00 element, long a, long b, long c, long d, long e)
    {
        ((BluetoothLeAdvertiser)w.sObject.get(a)).startAdvertising(
            w.mTKrossSystem.getValue(b, AdvertiseSettings.class),
            w.mTKrossSystem.getValue(c, AdvertiseData.class),
            w.mTKrossSystem.getValue(d, AdvertiseCallback.class)
        );
        return 0;
    }

    //void startAdvertising(AdvertiseSettings* settings, AdvertiseData* advertiseData, AdvertiseData* scanResponse, AdvertiseCallback* callback)
    public long visit(TEta00 element, long a, long b, long c, long d, long e)
    {
        ((BluetoothLeAdvertiser)w.sObject.get(a)).startAdvertising(
            w.mTKrossSystem.getValue(b, AdvertiseSettings.class),
            w.mTKrossSystem.getValue(c, AdvertiseData.class),
            w.mTKrossSystem.getValue(d, AdvertiseData.class),
            w.mTKrossSystem.getValue(e, AdvertiseCallback.class)
        );
        return 0;
    }

    //void stopAdvertising(AdvertiseCallback* callback)
    public long visit(TTheta00 element, long a, long b, long c, long d, long e)
    {
        ((BluetoothLeAdvertiser)w.sObject.get(a)).stopAdvertising(w.mTKrossSystem.getValue(b, AdvertiseCallback.class));
        return 0;
    }

    //*******************************************************************************
    //*************************** BluetoothLeScanner ********************************
    //*******************************************************************************

    //void flushPendingScanResults(ScanCallback* callback)
    public long visit(TIota00 element, long a, long b, long c, long d, long e)
    {
        ((BluetoothLeScanner)w.sObject.get(a)).flushPendingScanResults(w.mTKrossSystem.getValue(b, ScanCallback.class));
        return 0;
    }

    //void startScan(ScanCallback* callback)
    public long visit(TKappa00 element, long a, long b, long c, long d, long e)
    {
        ((BluetoothLeScanner)w.sObject.get(a)).startScan(w.mTKrossSystem.getValue(b, ScanCallback.class));
        return 0;
    }

    //void stopScan(ScanCallback* callback)
    public long visit(TLambda00 element, long a, long b, long c, long d, long e)
    {
        ((BluetoothLeScanner)w.sObject.get(a)).stopScan(w.mTKrossSystem.getValue(b, ScanCallback.class));
        return 0;
    }

    //*******************************************************************************
    //********************************* ScanCallback ********************************
    //*******************************************************************************
    //ScanCallback()
    public long visit(TMu00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new TScanCallback(w, a));
        return 0;
    }

    //*******************************************************************************
    //******************************** ScanRecord ***********************************
    //*******************************************************************************
    //int getAdvertiseFlags()
    public long visit(TNu00 element, long a, long b, long c, long d, long e)
    {
        return ((ScanRecord)w.sObject.get(a)).getAdvertiseFlags();
    }

    //NArray<String> getServiceUuids()
    public long visit(TXi00 element, long a, long b, long c, long d, long e)
    {
        List<String> vaString = new ArrayList<String>();
        List<ParcelUuid> vaParcelUuid = ((ScanRecord)w.sObject.get(a)).getServiceUuids();

        for (ParcelUuid vParcelUuid : vaParcelUuid) {
            vaString.add(vParcelUuid.toString());
        }
        return w.mTKrossSystem.putNext(vaString);
    }

    //*******************************************************************************
    //******************************** ScanResult ***********************************
    //*******************************************************************************
    //ScanResult(BluetoothDevice* device, ScanRecord* scanRecord, int rssi, long timestampNanos)
    public long visit(TOmicron00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new ScanResult(
            w.mTKrossSystem.getValue(b, BluetoothDevice.class),
            w.mTKrossSystem.getValue(c, ScanRecord.class),
            (int)d,
            e
        ));
        return 0;
    }

    //BluetoothDevice* getDevice()
    public long visit(TPi00 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.emplaceKey(b, ((ScanResult)w.sObject.get(a)).getDevice());
    }

    //ScanRecord* getScanRecord()
    public long visit(TRho00 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.emplaceKey(b, ((ScanResult)w.sObject.get(a)).getScanRecord());
    }
}
