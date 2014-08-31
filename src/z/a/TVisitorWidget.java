package z.a;

import android.content.Context;
import android.widget.LinearLayout;
import android.widget.TextView;

public class TVisitorWidget extends TVisitor
{
	public TVisitorWidget(TWrapper w) {
		super(w);
	}

	public long visit(TLambda00 element, long a, long b, long c, long d)
	{
		w.sObject.put("" + a, new LinearLayout((Context)w.sObject.get("" + b)));
		return 0;
	}

	public long visit(TTau01 element, long a, long b, long c, long d)
	{
		w.sObject.put("" + a, new TextView((Context)w.sObject.get("" + b)));
		return 0;
	}

	public long visit(TUpsilon01 element, long a, long b, long c, long d)
	{
		((TextView)w.sObject.get("" + a)).setTextSize(b);
		return 0;
	}

	public long visit(TPhi01 element, long a, long b, long c, long d)
	{
		((TextView)w.sObject.get("" + a)).setText((String)w.tFrame.nRunObject(b));
		return 0;
	}
}
