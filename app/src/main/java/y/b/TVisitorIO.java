package y.b;

import java.io.InputStream;
import java.io.OutputStream;

public class TVisitorIO extends TKrossVisitor
{
    public TVisitorIO(TWrapper w) {
        super(w);
    }

    //*******************************************************************************
    //********************************* InputStream *********************************
    //*******************************************************************************

    // void close();
    public long visit(TAlpha00 element, long a, long b, long c, long d, long e)
    {
        long err = 0;
        try {
            ((InputStream)w.sObject.get(a)).close();
        }
        catch (Exception vException) {
            if (w.doDebug) vException.printStackTrace();
            err = 1;
        }
        return err;
    }

    // int read(String& buffer, int byteOffset, int byteCount)
    public long visit(TBeta00 element, long a, long b, long c, long d, long e)
    {
        long err = 0;
        byte[] aByte = new byte[(int)d];
        String vString = "";

        try {
            // Blocks and returns the number of bytes read or -1 if end of the stream is reached
            err = ((InputStream)w.sObject.get(a)).read(aByte);
        }
        catch (Exception vException) {
            if (w.doDebug) vException.printStackTrace();
            err = -2;
        }
        if (err >= 0) {
            try {
                vString = new String(aByte, "UTF-8");
            }
            catch (Exception vException) {
                if (w.doDebug) vException.printStackTrace();
                err = -3;
            }
        }
        if (err >= 0) {
            err = w.mTKrossSystem.putNext(vString);
        }
        return err;
    }

    //*******************************************************************************
    //********************************* OutputStream *********************************
    //*******************************************************************************

    // void close();
    public long visit(TAlpha01 element, long a, long b, long c, long d, long e)
    {
        long err = 0;
        try {
            ((OutputStream)w.sObject.get(a)).close();
        }
        catch (Exception vException) {
            if (w.doDebug) vException.printStackTrace();
            err = -1;
        }
        return err;
    }

    // void write(String b)
    public long visit(TBeta01 element, long a, long b, long c, long d, long e)
    {
        long err = 0;
        try {
            //String vString = (String)w.mTKrossSystem.nRunObject(b);
            //byte[] vaByte = vString.getBytes();
            //((OutputStream)w.sObject.get(a)).write(vaByte);
            ((OutputStream)w.sObject.get(a)).write(((String)w.mTKrossSystem.nRunObject(b)).getBytes());
        }
        catch (Exception vException) {
            if (w.doDebug) vException.printStackTrace();
            err = -1;
        }
        return err;
    }
}
