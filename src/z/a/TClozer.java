package z.a;

import java.nio.ByteBuffer;

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
    	ByteBuffer bbNElement = nInit(w.aTElement);

    	for (j = 0 ; j < bbNElement.capacity()/4 && j < w.aTElement.length; j++) {
    		w.aTElement[j].n = bbNElement.getLong(j);
    	}
    	w.tView = (TView)tRunObject(w.alpha);
    }

    public long tRunLong(TElement tElement) {
    	return nRunLong(tElement.n);
    }

    public Object tRunObject(TElement tElement) {
    	return nRunObject(tElement.n);
    }
    
    public static native ByteBuffer	nInit(TElement[] aTElement);
	public static native long		nRunLong(long nElement);
    public static native Object		nRunObject(long nElement);
}
