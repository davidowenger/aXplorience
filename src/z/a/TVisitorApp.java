package z.a;

import android.app.Activity;
import android.view.View;

public class TVisitorApp extends TVisitor
{
	public TVisitorApp(TWrapper w) {
		super(w);
	}

	public long visit(TAlpha element, long a, long b, long c)
	{
		((Activity)w.vObject.get("" + a)).setContentView((View)w.vObject.get("" + b));
		return 0;
	}
}
