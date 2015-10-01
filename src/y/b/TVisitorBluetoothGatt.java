package y.b;

import java.util.UUID;

import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothGatt;
import android.bluetooth.BluetoothGattCharacteristic;
import android.bluetooth.BluetoothGattDescriptor;
import android.bluetooth.BluetoothGattServer;
import android.bluetooth.BluetoothGattService;

public class TVisitorBluetoothGatt extends TVisitor
{
    public TVisitorBluetoothGatt(TWrapper w) {
        super(w);
    }

    //*******************************************************************************
    //********************************* BluetoothGatt *******************************
    //*******************************************************************************
    //void close()
    public long visit(TTau00 element, long a, long b, long c, long d, long e)
    {
        ((BluetoothGatt)w.sObject.get(a)).close();
        return 0;
    }

    //void connect()
    public long visit(TUpsilon00 element, long a, long b, long c, long d, long e)
    {
        return ( ((BluetoothGatt)w.sObject.get(a)).connect() ? 1 : 0 );
    }

    //void disconnect()
    public long visit(TPhi00 element, long a, long b, long c, long d, long e)
    {
        ((BluetoothGatt)w.sObject.get(a)).disconnect();
        return 0;
    }

    //bool discoverServices()
    public long visit(TSigma00 element, long a, long b, long c, long d, long e)
    {
        return ( ((BluetoothGatt)w.sObject.get(a)).discoverServices() ? 1 : 0 );
    }

    //BluetoothGattService* getService(const String& uuid)
    public long visit(TPi00 element, long a, long b, long c, long d, long e)
    {
        return w.tFrame.emplaceKey(b, ((BluetoothGatt)w.sObject.get(a)).getService(UUID.fromString((String)w.tFrame.nRunObject(c))));
    }

    //BluetoothGattService* getServices()
    public long visit(TBeta01 element, long a, long b, long c, long d, long e)
    {
        return w.tFrame.putNext(((BluetoothGatt)w.sObject.get(a)).getServices());
    }

    //bool setCharacteristicNotification(BluetoothGattCharacteristic* characteristic, bool enable)
    public long visit(TAlpha00 element, long a, long b, long c, long d, long e)
    {
        return ( ((BluetoothGatt)w.sObject.get(a)).setCharacteristicNotification(w.tFrame.getValue(b, BluetoothGattCharacteristic.class), c != 0) ? 1 : 0 );
    }

    //bool writeCharacteristic(BluetoothGattCharacteristic* characteristic)
    public long visit(TBeta00 element, long a, long b, long c, long d, long e)
    {
        return ( ((BluetoothGatt)w.sObject.get(a)).writeCharacteristic(w.tFrame.getValue(b, BluetoothGattCharacteristic.class)) ? 1 : 0 );
    }

    //*******************************************************************************
    //*************************** BluetoothGattCallback *****************************
    //*******************************************************************************
    //BluetoothGattCallback()
    public long visit(TGamma00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new TBluetoothGattCallback(w, a));
        return 0;
    }

    //*******************************************************************************
    //********************* BluetoothGattCharacteristic *****************************
    //*******************************************************************************
    //BluetoothGattCharacteristic(const String& uuid, int properties, int permissions)
    public long visit(TDelta00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new BluetoothGattCharacteristic(UUID.fromString((String)w.tFrame.nRunObject(b)), (int)c, (int)d));
        return 0;
    }

    //bool addDescriptor(BluetoothGattDescriptor* descriptor)
    public long visit(TUpsilon01 element, long a, long b, long c, long d, long e)
    {
        return ( ((BluetoothGattCharacteristic)w.sObject.get(a)).addDescriptor(w.tFrame.getValue(b, BluetoothGattDescriptor.class)) ? 1 : 0 );
    }

    //BluetoothGattDescriptor* getDescriptor(const String& uuid)
    public long visit(TGamma01 element, long a, long b, long c, long d, long e)
    {
        return w.tFrame.emplaceKey(b, ((BluetoothGattCharacteristic)w.sObject.get(a)).getDescriptor(UUID.fromString((String)w.tFrame.nRunObject(c))));
    }

    //NArray<BluetoothGattDescriptor*> getDescriptors()
    public long visit(TDelta01 element, long a, long b, long c, long d, long e)
    {
        return w.tFrame.putNext(((BluetoothGattCharacteristic)w.sObject.get(a)).getDescriptors());
    }

    //int getProperties()
    public long visit(TEpsilon01 element, long a, long b, long c, long d, long e)
    {
        return ((BluetoothGattCharacteristic)w.sObject.get(a)).getProperties();
    }

    //String getUuid()
    public long visit(TDzeta01 element, long a, long b, long c, long d, long e)
    {
        return w.tFrame.putNext(((BluetoothGattCharacteristic)w.sObject.get(a)).getUuid().toString());
    }

    //NArray<nubyte>* getValue()
    public long visit(TEpsilon00 element, long a, long b, long c, long d, long e)
    {
        return w.tFrame.putNext(((BluetoothGattCharacteristic)w.sObject.get(a)).getValue());
    }

    //String getStringValue(int offset)
    public long visit(TDzeta00 element, long a, long b, long c, long d, long e)
    {
        return w.tFrame.putNext(((BluetoothGattCharacteristic)w.sObject.get(a)).getStringValue((int)b));
    }

    //bool setValue(NArray<nubyte>* value)
    public long visit(TEta00 element, long a, long b, long c, long d, long e)
    {
        int vcIndex;
        int vaValueInt[] = (int[])w.aObject.remove((int)b);
        byte vaValue[] = new byte[vaValueInt.length];

        for (vcIndex = 0 ; vcIndex < vaValueInt.length ; ++vcIndex) {
            vaValue[vcIndex] = (byte)vaValueInt[vcIndex];
        };
        return ( ((BluetoothGattCharacteristic)w.sObject.get(a)).setValue(vaValue) ? 1 : 0 );
    }

    //bool setValue(const String& value)
    public long visit(TTheta00 element, long a, long b, long c, long d, long e)
    {
        return ( ((BluetoothGattCharacteristic)w.sObject.get(a)).setValue((String)w.tFrame.nRunObject(b)) ? 1 : 0 );
    }

    //void setWriteType (int writeType)
    public long visit(TIota00 element, long a, long b, long c, long d, long e)
    {
        ((BluetoothGattCharacteristic)w.sObject.get(a)).setWriteType((int)b);
        return 0;
    }

    //*******************************************************************************
    //********************** BluetoothGattDescriptor ********************************
    //*******************************************************************************
    //BluetoothGattDescriptor(const String& uuid, int permissions)
    public long visit(TEta01 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new BluetoothGattDescriptor(UUID.fromString((String)w.tFrame.nRunObject(b)), (int)c));
        return 0;
    }

    //int getPermissions()
    public long visit(TTheta01 element, long a, long b, long c, long d, long e)
    {
        return ((BluetoothGattDescriptor)w.sObject.get(a)).getPermissions();
    }

    //String getUuid()
    public long visit(TIota01 element, long a, long b, long c, long d, long e)
    {
        return w.tFrame.putNext(((BluetoothGattDescriptor)w.sObject.get(a)).getUuid().toString());
    }

    //NArray<nubyte>* getValue()
    public long visit(TKappa01 element, long a, long b, long c, long d, long e)
    {
        return w.tFrame.putNext(((BluetoothGattDescriptor)w.sObject.get(a)).getValue());
    }

    //bool setValue(NArray<nubyte>* value)
    public long visit(TLambda01 element, long a, long b, long c, long d, long e)
    {
        int vcIndex;
        int vaValueInt[] = (int[])w.aObject.remove((int)b);
        byte vaValue[] = new byte[vaValueInt.length];

        for (vcIndex = 0 ; vcIndex < vaValueInt.length ; ++vcIndex) {
            vaValue[vcIndex] = (byte)vaValueInt[vcIndex];
        };
        return ( ((BluetoothGattDescriptor)w.sObject.get(a)).setValue(vaValue) ? 1 : 0 );
    }

    //*******************************************************************************
    //****************************** BluetoothGattServer ****************************
    //*******************************************************************************
    //bool addService(BluetoothGattService* service)
    public long visit(TKappa00 element, long a, long b, long c, long d, long e)
    {
        return ( ((BluetoothGattServer)w.sObject.get(a)).addService(w.tFrame.getValue(b, BluetoothGattService.class)) ? 1 : 0 );
    }

    //void cancelConnection(BluetoothDevice* device)
    public long visit(TKhi00 element, long a, long b, long c, long d, long e)
    {
        ((BluetoothGattServer)w.sObject.get(a)).cancelConnection(w.tFrame.getValue(b, BluetoothDevice.class));
        return 0;
    }

    //void clearServices()
    public long visit(TPsi00 element, long a, long b, long c, long d, long e)
    {
        ((BluetoothGattServer)w.sObject.get(a)).clearServices();
        return 0;
    }

    //void close()
    public long visit(TOmega00 element, long a, long b, long c, long d, long e)
    {
        ((BluetoothGattServer)w.sObject.get(a)).close();
        return 0;
    }

    //BluetoothGattService* getService(const String& uuid)
    public long visit(TMu01 element, long a, long b, long c, long d, long e)
    {
        return w.tFrame.emplaceKey(b, ((BluetoothGattServer)w.sObject.get(a)).getService(UUID.fromString((String)w.tFrame.nRunObject(c))));
    }

    //NArray<BluetoothGattService*> getServices()
    public long visit(TNu01 element, long a, long b, long c, long d, long e)
    {
        return w.tFrame.putNext(((BluetoothGattServer)w.sObject.get(a)).getServices());
    }

    //bool notifyCharacteristicChanged(BluetoothDevice* device, BluetoothGattCharacteristic* characteristic, bool confirm)
    public long visit(TLambda00 element, long a, long b, long c, long d, long e)
    {
        return ( ((BluetoothGattServer)w.sObject.get(a)).notifyCharacteristicChanged(
            w.tFrame.getValue(b, BluetoothDevice.class),
            w.tFrame.getValue(c, BluetoothGattCharacteristic.class),
            d != 0
        ) ? 1 : 0 );
    }

    //bool sendResponse(BluetoothDevice* device, int requestId, int status, int offset, NArray<nubyte>* value)
    public long visit(TMu00 element, long a, long b, long c, long d, long e)
    {
        int vcIndex;
        int vaValueInt[] = (int[])w.aObject.remove((int)e);
        byte vaValue[] = new byte[vaValueInt.length];

        for (vcIndex = 0 ; vcIndex < vaValueInt.length ; ++vcIndex) {
            vaValue[vcIndex] = (byte)vaValueInt[vcIndex];
        };
        return ( ((BluetoothGattServer)w.sObject.get(a)).sendResponse(
            w.tFrame.getValue(b, BluetoothDevice.class),
            (int)c,
            (int)d,
            0,
            vaValue
        ) ? 1 : 0 );
    }

    //*******************************************************************************
    //********************** BluetoothGattServerCallback ****************************
    //*******************************************************************************
    //BluetoothGattServerCallback()
    public long visit(TNu00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new TBluetoothGattServerCallback(w, a));
        return 0;
    }

    //*******************************************************************************
    //***************************** BluetoothGattService ****************************
    //*******************************************************************************
    //BluetoothGattService(const String& uuid, int serviceType)
    public long visit(TXi00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new BluetoothGattService(UUID.fromString((String)w.tFrame.nRunObject(b)), (int)c));
        return 0;
    }

    //bool addCharacteristic(BluetoothGattCharacteristic* characteristic)
    public long visit(TOmicron00 element, long a, long b, long c, long d, long e)
    {
        return ( ((BluetoothGattService)w.sObject.get(a)).addCharacteristic(w.tFrame.getValue(b, BluetoothGattCharacteristic.class)) ? 1 : 0 );
    }

    //bool addService(BluetoothGattService* service)
    public long visit(TXi01 element, long a, long b, long c, long d, long e)
    {
        return ( ((BluetoothGattService)w.sObject.get(a)).addService(w.tFrame.getValue(b, BluetoothGattService.class)) ? 1 : 0 );
    }

    //BluetoothGattCharacteristic* getCharacteristic(const String& uuid)
    public long visit(TOmicron01 element, long a, long b, long c, long d, long e)
    {
        return w.tFrame.emplaceKey(b, ((BluetoothGattService)w.sObject.get(a)).getCharacteristic(UUID.fromString((String)w.tFrame.nRunObject(c))));
    }

    //NArray<BluetoothGattCharacteristic*> getCharacteristics()
    public long visit(TPi01 element, long a, long b, long c, long d, long e)
    {
        return w.tFrame.putNext(((BluetoothGattService)w.sObject.get(a)).getCharacteristics());
    }

    //NArray<BluetoothGattService*> getIncludedServices()
    public long visit(TRho01 element, long a, long b, long c, long d, long e)
    {
        return w.tFrame.putNext(((BluetoothGattService)w.sObject.get(a)).getIncludedServices());
    }

    //int getInstanceId()
    public long visit(TTau01 element, long a, long b, long c, long d, long e)
    {
        return ((BluetoothGattService)w.sObject.get(a)).getInstanceId();
    }

    //int getType()
    public long visit(TSigma01 element, long a, long b, long c, long d, long e)
    {
        return ((BluetoothGattService)w.sObject.get(a)).getType();
    }

    //String getUuid ()
    public long visit(TAlpha01 element, long a, long b, long c, long d, long e)
    {
        return w.tFrame.putNext(((BluetoothGattService)w.sObject.get(a)).getUuid().toString());
    }

}
