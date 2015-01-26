package z.a;

import java.util.ArrayList;
import java.util.UUID;

import android.bluetooth.BluetoothDevice;
import android.content.Context;
import android.content.Intent;
import android.view.Menu;

public class TWrapper
{
    static final int ITEM_EDIT = 100001;
    static final int ITEM_DELETE = 100002;
    static final int ITEM_SAVE = 100003;
    static final int ITEM_ADD = 100004;

    static final int SWIPE_MIN_DISTANCE = 120;
    static final int SWIPE_MAX_OFF_PATH = 250;
    static final int SWIPE_THRESHOLD_VELOCITY = 200;

    static final String BASE_TAG = "BASE_TAG";

	int cAPI;
	String mac;
	String serviceName;
	UUID[] aUUID;

	DBHandler dbh;
	BO_Seed boSeed;

	Context context;
	Menu mMenu;
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
