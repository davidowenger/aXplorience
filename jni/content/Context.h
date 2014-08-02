#ifndef __Context_H__
#define __Context_H__

namespace NNSUser
{

class Context
{
public:
	Context()
		: w(NULL)
	{
	}

	virtual ~Context()
	{
	}

	NWrapper* w;
};

} // End namespace

#endif
