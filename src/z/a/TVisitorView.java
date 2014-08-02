package z.a;

import android.view.View;
import android.view.ViewGroup;

public class TVisitorView extends TVisitor
{
	public TVisitorView(TWrapper w) {
		super(w);
	}

	public long visit(TAlpha element, long a, long b, long c)
	{
		((ViewGroup)w.vObject.get("" + a)).addView((View)w.vObject.get("" + b));
		return 0;
	}
}
