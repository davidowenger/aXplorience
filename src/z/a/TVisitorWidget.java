package z.a;

import android.content.Context;
import android.widget.LinearLayout;
import android.widget.TextView;

public class TVisitorWidget extends TVisitor
{
	public TVisitorWidget(TWrapper w) {
		super(w);
	}

	public long visit(TLambda element, long a, long b, long c)
	{
		w.vObject.put("" + a, new LinearLayout((Context)w.vObject.get("" + b)));
		return 0;
	}

	public long visit(TTau element, long a, long b, long c)
	{
		w.vObject.put("" + a, new TextView((Context)w.vObject.get("" + b)));
		return 0;
	}

	public long visit(TUpsilon element, long a, long b, long c)
	{
		((TextView)w.vObject.get("" + a)).setTextSize(b);
		return 0;
	}

	public long visit(TPhi element, long a, long b, long c)
	{
		((TextView)w.vObject.get("" + a)).setText((String)w.tFrame.nRunObject(w.omega, b));
		return 0;
	}
}
