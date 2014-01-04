package z.a;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;

public class TClozer extends TFrame
{
	public TWrapper w;

    public TClozer(TWrapper w) {
    	this.w = w;
    }

    public void tInit() {
    	int j;

    	w.aTElement = new TElement[]{
	    	w.alpha = new TAlpha(),
	    	w.beta = new TBeta(),
	    	w.gamma = new TGamma()
    	};
    	
    	// Create a <ByteBuffer> in the native library and get a shared reference to it 
    	ByteBuffer bbNElement = nInit(w.aTElement);
    	bbNElement.order(ByteOrder.nativeOrder());

    	// <long> has a size of 4 bytes and the capacity of a <ByteBuffer> is defined in bytes  
    	int nCapacity = bbNElement.capacity()/4;

    	for (j = 0 ; j < nCapacity && j < w.aTElement.length; j++) {
    		w.aTElement[j].n = bbNElement.getLong(j);
    	}
    	if (j < nCapacity) {
    		bbNElement.getLong(j++);
    	}
    	w.tView = (TView)nRunObject(w.alpha.n);
    }

    public static native ByteBuffer	nInit(TElement[] aTElement);
    public static native Object		nRunObject(long nElement);
}
