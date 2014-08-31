#ifndef __Tables_H__
#define __Tables_H__

namespace NSDEVICE
{

class Table_Drop : public DBTable
{
	void init() {
		aField = {
			"id",
			"mac",
			"id_drop",
			"id_cat",
			"date",
			"title",
			"text",
			"archived",
		};
	}
};

} // End namespace

#endif
