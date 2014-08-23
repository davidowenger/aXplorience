package z.a;

import java.util.ArrayList;
import java.util.UUID;

import android.bluetooth.BluetoothDevice;
import android.content.Context;

public class TWrapper
{
	int cAPI;
	String mac;
	String serviceName;
	UUID[] aUUID;

	DBHandler dbh;
	BO_Seed boSeed;

	Context context;
	TApp tApp;
	TAppHandler tAppHandler;
	TFrame tFrame;
	TConfig tConfig;
	TBluetooth tBluetooth;
	TCore tCore;
	TClient tClient;

	ArrayList<BluetoothDevice> aDiscoveredDevice;
	ArrayList<BO_Drop> aBOSeed;
	ArrayList<BO_Drop> aBODrop;
	ArrayList<TServer> aTServer;
	ArrayList<TPeer> aTPeer;
}
