package y.b;

import android.app.Activity;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.os.StrictMode;
import android.view.Menu;
import android.view.MenuItem;

public class TActivity extends Activity
{
    public long n;
    public TWrapper w;

    // Called when the activity is first created
    protected void onCreate(Bundle vBundle)
    {
        // Init
        TVisitor.counter = 0;
        TElement.counter = 0;
        TWrapper.w = new TWrapper();;

        n = 0;
        w = TWrapper.w;
        w.doDebug = TWrapper.kDoDebug;
        w.isStrict = false;

        // Creeate
        if (w.isStrict) {
            StrictMode.setThreadPolicy(
                new StrictMode.ThreadPolicy.Builder()
                    .detectAll()
                    .penaltyLog()
                    .build()
            );
            StrictMode.setVmPolicy(
                new StrictMode.VmPolicy.Builder()
                    .detectAll()
                    .penaltyLog()
                    .build()
           );
        }
        w.context = getApplication();
        w.tActivity = this;
        w.tActivityHandler = new TActivityHandler(w);
        w.mTKrossSystem = new TKrossSystem(w);
        w.mTKrossSystem.tInit();

        // Call user onCreate event
        long vcKey;
        w.isAlive = true;
        w.mTVisitorAppActivity.nRun(w.mTAlpha00, n,
            (vcKey = w.mTKrossSystem.getKey(vBundle)) != -1 ? vcKey : w.mTKrossSystem.putKey(w.mTVisitorAppActivity.nRun(w.mTAlpha00, n, -1, 1), vBundle)
        );
    }

    protected void onRestart()
    {
        w.mTVisitorAppActivity.nRun(w.mTBeta00, n);
    }

    protected void onStart()
    {
        w.mTVisitorAppActivity.nRun(w.mTGamma00, n);
    }

    protected void onResume()
    {
        w.mTVisitorAppActivity.nRun(w.mTDelta00, n);
    }

    protected void onPause()
    {
        w.mTVisitorAppActivity.nRun(w.mTEpsilon00, n);
    }

    protected void onStop()
    {
        w.mTVisitorAppActivity.nRun(w.mTDzeta00, n);
    }

    protected void onDestroy()
    {
        w.mTVisitorAppActivity.nRun(w.mTEta00, n);
        w.isAlive = false;
        w.mTKrossSystem.nCancel(w.mTKrossSystem.n);
        w.mTKrossSystem.tCancel();
        w.mTKrossSystem = null;
        w.tActivityHandler.cancel();
        w.tActivityHandler = null;
        w.context = null;
        w.tActivity = null;

        w.mTAlpha00=null;
        w.mTBeta00=null;
        w.mTGamma00=null;
        w.mTDelta00=null;
        w.mTEpsilon00=null;
        w.mTDzeta00=null;
        w.mTEta00=null;
        w.mTTheta00=null;
        w.mTIota00=null;
        w.mTKappa00=null;
        w.mTLambda00=null;
        w.mTMu00=null;
        w.mTNu00=null;
        w.mTXi00=null;
        w.mTOmicron00=null;
        w.mTPi00=null;
        w.mTRho00=null;
        w.mTSigma00=null;
        w.mTTau00=null;
        w.mTUpsilon00=null;
        w.mTPhi00=null;
        w.mTKhi00=null;
        w.mTPsi00=null;
        w.mTOmega00=null;

        w.mTAlpha01=null;
        w.mTBeta01=null;
        w.mTGamma01=null;
        w.mTDelta01=null;
        w.mTEpsilon01=null;
        w.mTDzeta01=null;
        w.mTEta01=null;
        w.mTTheta01=null;
        w.mTIota01=null;
        w.mTKappa01=null;
        w.mTLambda01=null;
        w.mTMu01=null;
        w.mTNu01=null;
        w.mTXi01=null;
        w.mTOmicron01=null;
        w.mTPi01=null;
        w.mTRho01=null;
        w.mTSigma01=null;
        w.mTTau01=null;
        w.mTUpsilon01=null;
        w.mTPhi01=null;
        w.mTKhi01=null;
        w.mTPsi01=null;
        w.mTOmega01=null;

        w.mTAlpha02=null;
        w.mTBeta02=null;
        w.mTGamma02=null;
        w.mTDelta02=null;
        w.mTEpsilon02=null;
        w.mTDzeta02=null;
        w.mTEta02=null;
        w.mTTheta02=null;
        w.mTIota02=null;
        w.mTKappa02=null;
        w.mTLambda02=null;
        w.mTMu02=null;
        w.mTNu02=null;
        w.mTXi02=null;
        w.mTOmicron02=null;
        w.mTPi02=null;
        w.mTRho02=null;
        w.mTSigma02=null;
        w.mTTau02=null;
        w.mTUpsilon02=null;
        w.mTPhi02=null;
        w.mTKhi02=null;
        w.mTPsi02=null;
        w.mTOmega02=null;

        w.mTAlpha03=null;
        w.mTBeta03=null;
        w.mTGamma03=null;
        w.mTDelta03=null;
        w.mTEpsilon03=null;
        w.mTDzeta03=null;
        w.mTEta03=null;
        w.mTTheta03=null;
        w.mTIota03=null;
        w.mTKappa03=null;
        w.mTLambda03=null;
        w.mTMu03=null;
        w.mTNu03=null;
        w.mTXi03=null;
        w.mTOmicron03=null;
        w.mTPi03=null;
        w.mTRho03=null;
        w.mTSigma03=null;
        w.mTTau03=null;
        w.mTUpsilon03=null;
        w.mTPhi03=null;
        w.mTKhi03=null;
        w.mTPsi03=null;
        w.mTOmega03=null;

        w.mTVisitorApp=null;
        w.mTVisitorAppActivity=null;
        w.mTVisitorAppFragment=null;
        w.mTVisitorBluetooth=null;
        w.mTVisitorContent=null;
        w.mTVisitorContentRes=null;
        w.mTVisitorGraphics=null;
        w.mTVisitorIO=null;
        w.mTVisitorOS=null;
        w.mTVisitorUtil=null;
        w.mTVisitorView=null;
        w.mTVisitorViewView=null;
        w.mTVisitorViewViewGroup=null;
        w.mTVisitorWidget=null;
        w.mTVisitorWidgetLayout=null;
        w.mTVisitorWidgetView=null;
        w.tAndroid=null;

        w.aTElement=null;
        w.aTElement=null;
        w.aTVisitor=null;
        w.sTElement=null;
        w.sTVisitor=null;
        w.aObject=null;
        w.sObject=null;
        w.aAction=null;
        w.tActivityReceiver=null;

        w = null;
        TWrapper.w = null;
    }

    public void discoverable(int nTimeout)
    {
        Intent intentDiscoverable = new Intent(BluetoothAdapter.ACTION_REQUEST_DISCOVERABLE);
        intentDiscoverable.putExtra(BluetoothAdapter.EXTRA_DISCOVERABLE_DURATION, nTimeout);
        startActivityForResult(intentDiscoverable, 1);
    }

    protected void onActivityResult(int requestCode, int resultCode, Intent intent)
    {
        if (intent != null && intent.getAction() != null) {
            String action = intent.getAction();

            if (action.equals(BluetoothAdapter.ACTION_REQUEST_ENABLE)) {
                w.mTVisitorAppActivity.nRun(w.mTTheta00, n, 1, requestCode, resultCode, -1);
            } else if (action.equals(BluetoothAdapter.ACTION_REQUEST_DISCOVERABLE)) {
                w.mTVisitorAppActivity.nRun(w.mTTheta00, n, 2, requestCode, resultCode, intent.getIntExtra(BluetoothAdapter.EXTRA_DISCOVERABLE_DURATION, -1));
            }
        } else {
            w.mTVisitorAppActivity.nRun(w.mTTheta00, n, 2, requestCode, resultCode, -1);
        }
    }

    public void onBackPressed()
    {
        w.mTVisitorAppActivity.nRun(w.mTKhi00, n);
    }

    public boolean onCreateOptionsMenu(Menu vMenu)
    {
        long vcKey;
        return ( w.mTVisitorAppActivity.nRun(w.mTIota00, n,
            (vcKey = w.mTKrossSystem.getKey(vMenu)) != -1 ? vcKey : w.mTKrossSystem.putKey(w.mTVisitorAppActivity.nRun(w.mTIota00, n, -1, 1), vMenu)
        ) != 0 ? true : false );
    }

    public boolean onOptionsItemSelected(MenuItem vMenuItem)
    {
        long vcKey;
        return ( w.mTVisitorAppActivity.nRun(w.mTLambda00, n,
            (vcKey = w.mTKrossSystem.getKey(vMenuItem)) != -1 ? vcKey : w.mTKrossSystem.putKey(w.mTVisitorAppActivity.nRun(w.mTLambda00, n, -1, 1), vMenuItem)
        ) != 0 ? true : false );
    }

    public boolean onPrepareOptionsMenu(Menu vMenu)
    {
        long vcKey;
        return ( w.mTVisitorAppActivity.nRun(w.mTKappa00, n,
            (vcKey = w.mTKrossSystem.getKey(vMenu)) != -1 ? vcKey : w.mTKrossSystem.putKey(w.mTVisitorAppActivity.nRun(w.mTKappa00, n, -1, 1), vMenu)
        ) != 0 ? true : false );
    }

    public void onCreateParent(Bundle vBundle)
    {
        super.onCreate(vBundle);
    }

    public void onRestartParent()
    {
        super.onRestart();
    }

    public void onStartParent()
    {
        super.onStart();
    }

    public void onResumeParent()
    {
        super.onResume();
    }

    public void onPauseParent()
    {
        super.onPause();
    }

    public void onStopParent()
    {
        super.onStop();
    }

    public void onDestroyParent()
    {
        super.onDestroy();
    }

    public void onBackPressedParent()
    {
        super.onBackPressed();
    }

    public boolean onCreateOptionsMenuParent(Menu vMenu)
    {
        return super.onCreateOptionsMenu(vMenu);
    }

    public boolean onOptionsItemSelectedParent(MenuItem vMenuItem)
    {
        return super.onOptionsItemSelected(vMenuItem);
    }

    public boolean onPrepareOptionsMenuParent(Menu vMenu)
    {
        return super.onPrepareOptionsMenu(vMenu);
    }
}

class TActivityReceiver extends BroadcastReceiver
{
    public TWrapper w;

    public TActivityReceiver(TWrapper w)
    {
        this.w = w;
    }

    public void onReceive(Context context, Intent intent)
    {
        if (intent != null && intent.getAction() != null) {
            String action = intent.getAction();

            if (action.equals(BluetoothAdapter.ACTION_DISCOVERY_FINISHED)) {
                w.mTVisitorAppActivity.nRun(w.mTOmicron00, w.tActivity.n);
            } else if (action.equals(BluetoothAdapter.ACTION_DISCOVERY_STARTED)) {
                w.mTVisitorAppActivity.nRun(w.mTPi00, w.tActivity.n);
            } else if (action.equals(BluetoothDevice.ACTION_FOUND)) {
                Object vObject = intent.getParcelableExtra(BluetoothDevice.EXTRA_DEVICE);
                w.mTVisitorAppActivity.nRun(w.mTRho00, w.tActivity.n,
                    w.mTKrossSystem.putKey(w.mTVisitorAppActivity.nRun(w.mTRho00, w.tActivity.n, -1, 1), vObject)
                );
            } else if (action.equals(BluetoothAdapter.ACTION_LOCAL_NAME_CHANGED)) {
                String string = intent.getStringExtra(BluetoothAdapter.EXTRA_LOCAL_NAME);
                w.mTVisitorAppActivity.nRun(w.mTSigma00, w.tActivity.n, w.mTKrossSystem.putNext(string));
            } else if (action.equals(BluetoothAdapter.ACTION_SCAN_MODE_CHANGED)) {
                w.mTVisitorAppActivity.nRun(w.mTTau00, w.tActivity.n,
                    intent.getIntExtra(BluetoothAdapter.EXTRA_SCAN_MODE, -1),
                    intent.getIntExtra(BluetoothAdapter.EXTRA_PREVIOUS_SCAN_MODE,
                    -1)
                );
            } else if (action.equals(BluetoothAdapter.ACTION_STATE_CHANGED)) {
                w.mTVisitorAppActivity.nRun(w.mTUpsilon00, w.tActivity.n,
                    intent.getIntExtra(BluetoothAdapter.EXTRA_STATE, -1),
                    intent.getIntExtra(BluetoothAdapter.EXTRA_PREVIOUS_STATE,
                    -1)
                );
            }
        }
    }
}

class TActivityHandler extends Handler
{
    public TWrapper w;

    public TActivityHandler(TWrapper w)
    {
        this.w = w;
    }

    public void handleMessage(Message m)
    {
        w.mTVisitorAppActivity.nRun(w.mTPhi00, w.tActivity.n, (Long)m.obj);
    }

    public void cancel()
    {
        w = null;
        removeCallbacksAndMessages(null);
    }
}
