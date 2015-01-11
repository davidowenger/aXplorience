package z.a;

public class DBTable
{
	public String table;
	public String[] aField;
}

class Table_Drop extends DBTable
{
	public Table_Drop()
	{
		table = "Drop";
		aField = new String[] {
			"id",
			"mac",
			"id_drop",
			"id_cat",
			"date",
			"title",
			"text",
			"archived",
			"enabled",
			"checked",
			"buzzed",
		};
	}
}
