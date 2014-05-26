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

//template<class T>
//poly<T> poly<T>::operator+(poly<T> p) 
//{
//	int newnumvar = (_numvar>qpbf._numvar)?_numvar:qpbf._numvar;
//
//	QPBpoly<T> newqpbf;
//
//	QPBF::key_compare less= _QPBcoeff.key_comp();
//
//	QPBF::iterator it1=_QPBcoeff.begin(), it2=qpbf.firstTerm();
//	
//	for(;it1!=_QPBcoeff.end()&&it2!=qpbf.lastTerm();)
//	{
//		if(less(it1->first,it2->first))
//		{
//			newqpbf.addTerm2(it1->first.first,it1->first.second,it1->second);
//
//			it1++;
//		}
//		else if(less(it2->first,it1->first))
//		{
//			newqpbf.addTerm2(it2->first.first,it2->first.second,it2->second);
//
//			it2++;				
//		}
//		else
//		{
//			newqpbf.addTerm2(it1->first.first,it1->first.second,it1->second+it2->second);
//			
//			it1++;
//			it2++;			
//		}
//	}
//
//	for(;it1!=_QPBcoeff.end();it1++)
//	{
//		newqpbf.addTerm2(it1->first.first,it1->first.second,it1->second);
//	}
//
//	for(;it2!=qpbf.lastTerm();it2++)
//	{
//		newqpbf.addTerm2(it2->first.first,it2->first.second,it2->second);
//	}
//
//
//
//	return newqpbf;
//}

//template <class T>
//typename TERMS::iterator poly<T>::lastTerm()
//{
//
//}

#endif
