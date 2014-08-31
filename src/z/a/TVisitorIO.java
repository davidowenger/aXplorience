package z.a;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.LinkedList;

public class TVisitorIO extends TVisitor
{
	public TVisitorIO(TWrapper w) {
		super(w);
	}

	//*******************************************************************************
	//********************************* InputStream *********************************
	//*******************************************************************************

	//void close();
	public long visit(TAlpha00 element, long a, long b, long c, long d)
	{
		long err = 0;
		try {
			((InputStream)w.sObject.get("" + a)).close();
		}
		catch (IOException e) {
			if (w.doDebug) e.printStackTrace();
			err = -1;
		}
		return err;
	}

	//byte[] read(int byteCount);
	public long visit(TBeta00 element, long a, long b, long c, long d)
	{
		long err = -2;
		byte[] aByte = new byte[(int)b];

		try {
			err = ((InputStream)w.sObject.get("" + a)).read(aByte);
		}
		catch (IOException e) {
			if (w.doDebug) e.printStackTrace();
			err = -2;
		}
		if (err >= 0) {
			LinkedList<byte[]> aListByte = (LinkedList<byte[]>)Arrays.asList(Arrays.copyOf(aByte, (int)err));
			w.aObject.add(aListByte);
			err = w.aObject.lastIndexOf(aListByte);
		}
		return err;
	}

	//*******************************************************************************
	//********************************* OutputStream *********************************
	//*******************************************************************************

	//void close();
	public long visit(TAlpha01 element, long a, long b, long c, long d)
	{
		long err = 0;
		try {
			((InputStream)w.sObject.get("" + a)).close();
		}
		catch (IOException e) {
			if (w.doDebug) e.printStackTrace();
			err = -1;
		}
		return err;
	}

	//void write(String b)
	public long visit(TBeta01 element, long a, long b, long c, long d)
	{
		long err = 0;
		try {
			((OutputStream)w.sObject.get("" + a)).write(((String)w.tFrame.nRunObject(b)).getBytes());
		}
		catch (IOException e) {
			if (w.doDebug) e.printStackTrace();
			err = -1;
		}
		return err;
	}
}
