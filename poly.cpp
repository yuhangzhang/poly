#include "poly.h"

#ifndef _BPOLY_CPP_
#define _BPOLY_CPP_

template<class T>
poly<T>::poly(int numvar, int order)
{
	_numvar = numvar;

	_order = order;

	return;
}

template<class T>
int poly<T>::termid(const vector<int>& vars)
{
	for (vector<int>::const_iterator it = vars.begin(); it != vars.end(); it++) 
	{
	}
}

template<class T>
int poly<T>::numterm()
{
	for(TERMS::iterator it=_polynomial.begin();it!=_polynomial.end();)
	{
		TERMS::iterator tit=it++;

		if(tit->second==0) _polynomial.erase(tit);
	}

	return _polynomial.size();
}

#endif
