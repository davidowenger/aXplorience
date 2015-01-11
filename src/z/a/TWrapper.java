package z.a;

import java.util.ArrayList;
import java.util.UUID;

import android.bluetooth.BluetoothDevice;
import android.content.Context;
import android.content.Intent;

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
	Intent intent;

	ArrayList<BluetoothDevice> aDiscoveredDevice;
	ArrayList<BO_Drop> aBOSeed;
	ArrayList<BO_Drop> aBODrop;
	ArrayList<TWidgetMessage> aMessage;
	ArrayList<TWidgetMessage> aMessageSelected;
	ArrayList<TServer> aTServer;
	ArrayList<TPeer> aTPeer;
}
