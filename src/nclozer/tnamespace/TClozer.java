package nclozer.tnamespace;

import java.nio.ByteBuffer;

public class TClozer extends TFrame
{
	public TWrapper w;

    public TClozer(TWrapper w) {
    	this.w = w;
    }

    public void init() {
    	int j;

    	w.aTElement = new TElement[]{
    	    	w.alpha = new TAlpha(),
    	    	w.beta = new TBeta(),
    	    	w.gamma = new TGamma()
    	};
    	ByteBuffer bbNElement = initElement(w.aTElement);

    	for (j = 0 ; j < bbNElement.capacity()/4 && j < w.aTElement.length; j++) {
    		w.aTElement[j].n = bbNElement.getLong(j);
    	}
    	w.tView = (TView)runObject(w.alpha);
    }

    public long runLong(TElement tElement) {
    	return runLong(tElement.n);
    }

    public Object runObject(TElement tElement) {
    	return runObject(tElement.n);
    }
	public native ByteBuffer initElement(TElement[] aTElement);
	public native long 		runLong(long nElement);
	public native Object    runObject(long nElement);
}
