package z.a;

import java.nio.ByteBuffer;
import java.nio.LongBuffer;

public class TBufferLong
{
	public TWrapper w;
	public LongBuffer mBuffer;
	public Boolean mbDirect;
	
    public TBufferLong(TWrapper w, ByteBuffer buffer)
	{
    	this.w = w;
    	this.mBuffer = buffer.asLongBuffer();
    	this.mbDirect = buffer.isDirect();
    }

    public long get(TElement e)
	{
		return mBuffer.get(e.i);
    }

    public long[] get(TElement e, long[] aLong, int nLength)
	{
    	mBuffer.position(e.i);
    	mBuffer.get(aLong, 0, nLength);
		return aLong;
    }

	void set(TElement e, long nValue)
	{
		mBuffer.put(e.i, nValue);
    }
    
	void set(TElement e, long[] aLong, int nLength)
	{
    	mBuffer.position(e.i);
		mBuffer.put(aLong, 0, nLength);
    }
}
