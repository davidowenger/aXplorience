package z.a;

public class DBTable
{
	public String table;
	public String[] aField;
}

class Table_Thread extends DBTable
{
	public Table_Thread()
	{
		table = "Thread";
		aField = new String[] {
			"id",
			"id_thread",
			"id_type",
			"date",
		};
	}
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
			"link",
			"archived",
			"enabled",
			"checked",
			"buzzed",
		};
	}
}
