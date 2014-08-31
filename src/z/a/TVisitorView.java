package z.a;

import android.view.View;
import android.view.ViewGroup;

public class TVisitorView extends TVisitor
{
	public TVisitorView(TWrapper w) {
		super(w);
	}

	public long visit(TAlpha02 element, long a, long b, long c, long d)
	{
		((ViewGroup)w.sObject.get("" + a)).addView((View)w.sObject.get("" + b));
		return 0;
	}
}
