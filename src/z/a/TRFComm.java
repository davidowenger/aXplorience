package z.a;

/*
import java.io.IOException;
import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Random;
import java.util.UUID;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothServerSocket;
import android.bluetooth.BluetoothSocket;
import android.os.Binder;
import android.os.IBinder;
import android.os.ParcelUuid;
import android.os.RemoteException;

public class TRFComm
{
    public final int MAX_RFCOMM_CHANNEL = 30;
    public final int[] RESERVED_RFCOMM_CHANNELS = new int[] { 10, 11, 12, 19 };

	public TWrapper w;
	public Boolean[] aChannel;

	public TRFComm(TWrapper w)
	{
		int i;

		for (i = 0 ; i < MAX_RFCOMM_CHANNEL ; ++i) {
			aChannel[i] = true;
		}
		for (i = 0 ; i < RESERVED_RFCOMM_CHANNELS.length ; ++i) {
			aChannel[RESERVED_RFCOMM_CHANNELS[i]] = false;
		}
	}

	public listenRFComm()
	{
		ArrayList<Boolean> aAvailable = (ArrayList<Boolean>)Arrays.asList(Arrays.copyOf(aChannel, MAX_RFCOMM_CHANNEL));
	}


- live ? -> poke/tilt






























    public static final int MAX_RFCOMM_CHANNEL = 30;

    //* Keep TYPE_ fields in sync with BluetoothSocket.cpp //
    //package// static final int TYPE_RFCOMM = 1;
    //package// static final int TYPE_SCO = 2;
    //package// static final int TYPE_L2CAP = 3;

    //package// static final int EBADFD = 77;
    //package// static final int EADDRINUSE = 98;

	//*
	 * Picks RFCOMM channels until none are left.
	 * Avoids reserved channels.
	 //
	private static class RfcommChannelPicker {
		private static final int[] RESERVED_RFCOMM_CHANNELS =  new int[] {
			10,  // HFAG
			11,  // HSAG
			12,  // OPUSH
			19,  // PBAP
		};
		private static LinkedList<Integer> sChannels;  // master list of non-reserved channels
		private static Random sRandom;

		private final LinkedList<Integer> mChannels;  // local list of channels left to try

		private final UUID mUuid;

		public RfcommChannelPicker(UUID uuid) {
			synchronized (RfcommChannelPicker.class) {
				if (sChannels == null) {
					// lazy initialization of non-reserved rfcomm channels
					sChannels = new LinkedList<Integer>();
					for (int i = 1; i <= BluetoothSocket.MAX_RFCOMM_CHANNEL; i++) {
						sChannels.addLast(new Integer(i));
					}
					for (int reserved : RESERVED_RFCOMM_CHANNELS) {
						sChannels.remove(new Integer(reserved));
					}
					sRandom = new Random();
				}
				mChannels = (LinkedList<Integer>)sChannels.clone();
			}
			mUuid = uuid;
		}
		// Returns next random channel, or -1 if we're out //
		public int nextChannel() {
			if (mChannels.size() == 0) {
				return -1;
			}
			return mChannels.remove(sRandom.nextInt(mChannels.size()));
		}
	}
	public BluetoothServerSocket listenUsingInsecureRfcommWithServiceRecord(String name, UUID uuid)
			throws IOException
	{
		RfcommChannelPicker picker = new RfcommChannelPicker(uuid);

		BluetoothServerSocket socket;
		int channel;
		int errno;
		while (true) {
			channel = picker.nextChannel();

			if (channel == -1) {
				throw new IOException("No available channels");
			}

			socket = new BluetoothServerSocket(
					BluetoothSocket.TYPE_RFCOMM, true, true, channel);
			errno = socket.mSocket.bindListen();
			if (errno == 0) {
				if (DBG) Log.d(TAG, "listening on RFCOMM channel " + channel);
				break;  // success
			} else if (errno == BluetoothSocket.EADDRINUSE) {
				if (DBG) Log.d(TAG, "RFCOMM channel " + channel + " in use");
				try {
					socket.close();
				} catch (IOException e) {}
				continue;  // try another channel
			} else {
				try {
					socket.close();
				} catch (IOException e) {}
				socket.mSocket.throwErrnoNative(errno);  // Exception as a result of bindListen()
			}
		}

		int handle = -1;
		try {
			handle = mService.addRfcommServiceRecord(name, new ParcelUuid(uuid), channel,
					new Binder());
		} catch (RemoteException e) {Log.e(TAG, "", e);}
		if (handle == -1) {
			try {
				socket.close();
			} catch (IOException e) {}
			throw new IOException("Not able to register SDP record for " + name);
		}
		socket.setCloseHandler(mHandler, handle);
		return socket;
	}







	public class InsecureBluetooth {
		static private class InUse extends RuntimeException {
		}


		public static BluetoothServerSocket listenUsingRfcommWithServiceRecord(BluetoothAdapter adapter, String name, UUID uuid, boolean encrypt)
			throws IOException
		{
			try {
				Class c_rfcomm_channel_picker = null;
				Class[] children = BluetoothAdapter.class.getDeclaredClasses();

				for(Class c : children) {
					if (c.getCanonicalName().equals(BluetoothAdapter.class.getName() + ".RfcommChannelPicker")) {
						c_rfcomm_channel_picker = c;
						break;
					}
				}
				if(c_rfcomm_channel_picker == null) {
					throw new RuntimeException("can't find the rfcomm channel picker class");
				}
				Constructor constructor = c_rfcomm_channel_picker.getDeclaredConstructor(UUID.class);

				if(constructor == null) {
					throw new RuntimeException("can't find the constructor for rfcomm channel picker");
				}
				Object rfcomm_channel_picker = constructor.newInstance(new Object[] {uuid});
				Method m_next_channel = c_rfcomm_channel_picker.getDeclaredMethod("nextChannel", new Class[] {});
				m_next_channel.setAccessible(true);
				BluetoothServerSocket socket = null;

				int channel;
				int errno;

				while (true) {
					channel = (Integer)m_next_channel.invoke(rfcomm_channel_picker, new Object[] {});

					if (channel == -1) {
						throw new IOException("No available channels");
					}
					try {
						socket = listenUsingRfcomm(channel, encrypt);
						break;
					}
					catch(InUse e) {
						continue;
					}
				}
				Field f_internal_service = adapter.getClass().getDeclaredField("mService");
				f_internal_service.setAccessible(true);
				Object internal_service = f_internal_service.get(adapter);

				Method m_add_rfcomm_service_record = internal_service.getClass().getDeclaredMethod("addRfcommServiceRecord", new Class[] {String.class, ParcelUuid.class, int.class, IBinder.class});
				m_add_rfcomm_service_record.setAccessible(true);

				int handle = (Integer)m_add_rfcomm_service_record.invoke(internal_service, new Object[] { name, new ParcelUuid(uuid), channel, new Binder() } );

				if (handle == -1) {
					try {
						socket.close();
					}
					catch (IOException e)
					{
					}
					throw new IOException("Not able to register SDP record for " + name);
				}
				Field f_internal_handler = adapter.getClass().getDeclaredField("mHandler");
				f_internal_handler.setAccessible(true);
				Object internal_handler = f_internal_handler.get(adapter);

				Method m_set_close_handler = socket.getClass().getDeclaredMethod("setCloseHandler", new Class[] {Handler.class, int.class});
				m_set_close_handler.setAccessible(true);

				m_set_close_handler.invoke(socket, new Object[] { internal_handler, handle});
				return socket;
			} catch (NoSuchMethodException e) {
				throw new RuntimeException(e);
			} catch (NoSuchFieldException e) {
				throw new RuntimeException(e);
			} catch (IllegalAccessException e) {
				throw new RuntimeException(e);
			} catch (InstantiationException e) {
				throw new RuntimeException(e);
			} catch (InvocationTargetException e) {
				if (e.getCause() instanceof IOException) {
					throw (IOException)e.getCause();
				}
				throw new RuntimeException(e.getCause());
			}
		}


		private static BluetoothServerSocket listenUsingRfcomm(//BluetoothAdapter adapter, // int port, boolean encrypt, boolean reuse)
			throws IOException, InUse
		{
			BluetoothServerSocket socket = null;

			try {
				Constructor<BluetoothServerSocket> constructor = BluetoothServerSocket.class.getDeclaredConstructor(int.class, boolean.class, boolean.class, int.class);

				if (constructor == null) {
					throw new RuntimeException("can't find the constructor");
				}
				constructor.setAccessible(true);
				Field f_rfcomm_type = BluetoothSocket.class.getDeclaredField("TYPE_RFCOMM");
				f_rfcomm_type.setAccessible(true);
				int rfcomm_type = (Integer)f_rfcomm_type.get(null);

				Field f_e_addr_in_use = BluetoothSocket.class.getDeclaredField("EADDRINUSE");
				f_e_addr_in_use.setAccessible(true);
				int e_addr_in_use = (Integer)f_e_addr_in_use.get(null);

				socket = constructor.newInstance(new Object[] { rfcomm_type, false, encrypt, port });

				Field f_internal_socket = socket.getClass().getDeclaredField("mSocket");
				f_internal_socket.setAccessible(true);
				Object internal_socket = f_internal_socket.get(socket);
				Method m_bind_listen = internal_socket.getClass().getDeclaredMethod("bindListen", new Class[] {});
				m_bind_listen.setAccessible(true);
				Object result = m_bind_listen.invoke(internal_socket, new Object[] {});

				int errno = (Integer)result;

				if(reuse && errno == e_addr_in_use) {
					throw new InUse();
				} else if (errno != 0) {
					try {
						socket.close();
					}
					catch (IOException e)
					{
					}
					internal_socket.getClass().getMethod("throwErrnoNative", new Class[] {int.class}).invoke(internal_socket, new Object[] { errno });
				}
				return socket;
			} catch (NoSuchMethodException e) {
				throw new RuntimeException(e);
			} catch (NoSuchFieldException e) {
				throw new RuntimeException(e);
			} catch (IllegalAccessException e) {
				throw new RuntimeException(e);
			} catch (InstantiationException e) {
				throw new RuntimeException(e);
			} catch (InvocationTargetException e) {
				if (e.getCause() instanceof IOException) {
					throw (IOException)e.getCause();
				}
				throw new RuntimeException(e.getCause());
			}
		}

		public static BluetoothServerSocket listenUsingRfcomm(int port, boolean encrypt)
			throws IOException
		{
			return listenUsingRfcomm(port, encrypt, false);
		}






















		private static BluetoothSocket createRfcommSocketToServiceRecord(BluetoothDevice device, int port, UUID uuid, boolean encrypt) throws IOException {
			try {
				BluetoothSocket socket = null;
				Constructor<BluetoothSocket> constructor = BluetoothSocket.class.getDeclaredConstructor(
						int.class, int.class, boolean.class, boolean.class, BluetoothDevice.class, int.class, ParcelUuid.class);
				if(constructor == null)
					throw new RuntimeException("can't find the constructor for socket");

				constructor.setAccessible(true);
				Field f_rfcomm_type = BluetoothSocket.class.getDeclaredField("TYPE_RFCOMM");
				f_rfcomm_type.setAccessible(true);
				int rfcomm_type = (Integer)f_rfcomm_type.get(null);
				socket = constructor.newInstance(new Object[] { rfcomm_type, -1, false, true, device, port, uuid != null ? new ParcelUuid(uuid) : null} );
				return socket;
			} catch (NoSuchMethodException e) {
				throw new RuntimeException(e);
			} catch (NoSuchFieldException e) {
				throw new RuntimeException(e);
			} catch(IllegalAccessException e) {
				throw new RuntimeException(e);
			} catch(InstantiationException e) {
				throw new RuntimeException(e);
			} catch(InvocationTargetException e) {
				if(e.getCause() instanceof IOException) {
					throw (IOException)e.getCause();
				}
				throw new RuntimeException(e.getCause());
			}
		}
		public static BluetoothSocket createRfcommSocketToServiceRecord(BluetoothDevice device, UUID uuid, boolean encrypt) throws IOException{
			return createRfcommSocketToServiceRecord(device, -1, uuid, encrypt);
		}
		public static BluetoothSocket createRfcommSocket(BluetoothDevice device, int port, boolean encrypt) throws IOException {
			return createRfcommSocketToServiceRecord(device, port, null, encrypt);
		}
	}


}
*/
