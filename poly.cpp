#include "poly.h"

#ifndef _POLY_CPP_
#define _POLY_CPP_

template<class T>
poly<T>::poly()
{
	_lastvar = 0;

	_order = 0;

	return;
}

template<class T>
int poly<T>::numTerm()
{
	return _polynomial.size();
}

template<class T>
int poly<T>::lastVar()
{
	return _lastvar;
}

template<class T>
void poly<T>::addTerm(const std::vector<int>& vars, T coeff)
{
	std::pair<TERMS::iterator, bool> it = _polynomial.insert(std::make_pair(vars,coeff));

	if(it.second==false)//already got this term
	{
			(it.first)->second += coeff;
	}

	if(vars.back()>_lastvar) _lastvar = vars.back();
	if(int(vars.size())>_order ) _order = int(vars.size());

	return;
}


template<class T>
T poly<T>::getTerm(const std::vector<int>& vars)
{
	TERMS::iterator it = _polynomial.find(vars);

	if(it == _polynomial.end())//already got this term
	{
		return 0;
	}
	else
	{
		return it->second;
	}

}

template<class T>
poly<T> poly<T>::operator+(poly<T> p) 
{
	poly<T> newp;

	TERMS::key_compare less= _polynomial.key_comp();

	TERMS::iterator it1;
	TERMS::iterator it2;
	
	for(it1=_polynomial.begin(),it2=p.firstTerm();it1!=_polynomial.end()&&it2!=p.lastTerm();)
	{
		if(less(it1->first,it2->first))
		{
			newp.addTerm(it1->first,it1->second);

			it1++;
		}
		else if(less(it2->first,it1->first))
		{
			newp.addTerm(it2->first,it2->second);

			it2++;				
		}
		else
		{
			newp.addTerm(it1->first,it1->second+it2->second);

			it1++;
			it2++;			
		}
	}

	for(;it1!=_polynomial.end();it1++)
	{
		newp.addTerm(it1->first,it1->second);
	}

	for(;it2!=p.lastTerm();it2++)
	{
		newp.addTerm(it2->first,it2->second);
	}



	return newp;
}

template<class T>
poly<T> poly<T>::operator-(poly<T> p) 
{
	poly<T> newp;

	TERMS::key_compare less= _polynomial.key_comp();

	TERMS::iterator it1;
	TERMS::iterator it2;
	
	for(it1=_polynomial.begin(),it2=p.firstTerm();it1!=_polynomial.end()&&it2!=p.lastTerm();)
	{
		if(less(it1->first,it2->first))
		{
			newp.addTerm(it1->first,it1->second);

			it1++;
		}
		else if(less(it2->first,it1->first))
		{
			newp.addTerm(it2->first,-(it2->second));

			it2++;				
		}
		else
		{
			newp.addTerm(it1->first,it1->second-it2->second);

			it1++;
			it2++;			
		}
	}

	for(;it1!=_polynomial.end();it1++)
	{
		newp.addTerm(it1->first,it1->second);
	}

	for(;it2!=p.lastTerm();it2++)
	{
		newp.addTerm(it2->first,-(it2->second));
	}



	return newp;
}


template<class T>
poly<T> poly<T>::operator*(T u) 
{
	poly<T> newp;

	TERMS::iterator it;
	
	for(it=_polynomial.begin();it!=_polynomial.end();it++)
	{
		newp.addTerm(it->first,(it->second)*u);
	}

	return newp;
}


template <class T>
typename poly<T>::TERMS::iterator poly<T>::firstTerm()
{
	return _polynomial.begin();
}

template <class T>
typename poly<T>::TERMS::iterator poly<T>::lastTerm()
{
	return _polynomial.end();
}


template<class T>
void poly<T>::destroy()
{
	_lastvar = 0;
	_order = 0;
	_polynomial.clear();
	return;

}

template<class T>
void poly<T>::clean()
{
	_lastvar = 0;
	_order = 0;

	for(TERMS::iterator it=_polynomial.begin();it!=_polynomial.end();)
	{
		TERMS::iterator it2=it;
		it++;

		if(it2->second==0) _polynomial.erase(it2);
		else
		{
			if(it2->first.back()>_lastvar) _lastvar = it2->first.back();
			if(it2->first.size()>_order ) _order = int(it2->first.size());
		}
	}

	return;
}

#endif
