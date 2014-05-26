#include "poly.h"

#ifndef _POLY_CPP_
#define _POLY_CPP_

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
	int id=0;
	for(int i=1;i<=vars.size();i++)
	{
		id += combination(_numvar,i);
	}

	int order=vars.size();
	for (vector<int>::const_iterator it = vars.begin(); it != vars.end(); it++) 
	{
		id += it
	}
}

template<class T>
int poly<T>::numterm()
{
	//clean 0 terms first
	for(TERMS::iterator it=_polynomial.begin();it!=_polynomial.end();)
	{
		TERMS::iterator tit=it++;

		if(tit->second==0) _polynomial.erase(tit);
	}

	return _polynomial.size();
}

template<class T>
int poly<T>::maxsize()
{
	int total = 0;

	for(int i=1;i<=_order;i++)
	{
		total += combination(_numvar,i);
	}

	return total;
}

template<class T>
int poly<T>::combination(int m, int n)
{
	if(n>m)
	{
		return -1;
	}
	else if(n==0) 
	{
			return 1;
	}
	else
	{
		int total = 1;
	
		for(int i=m;i>m-n;i--)
		{
			total *= i;
		}

		for(int i=n;i>0;i--)
		{
			total /= i;
		}

		return total;
	}
}

#endif
