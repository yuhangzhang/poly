#include <map>
#include <vector>

using namespace std;

#ifndef _POLY_H_
#define _POLY_H_

template<class T>
class poly
{
public:
	typedef typename std::map<vector<int>,T> TERMS;
	poly();
	int numTerm();//return the number of terms with nonezero parameters
	int lastVar();//return the largest variable-id

	void addTerm(const std::vector<int>& vars, T coeff);
	T getTerm(const std::vector<int>& vars);
	poly<T> operator+(poly<T> p);
	poly<T> operator-(poly<T> p);
	poly<T> operator*(T u);


	typename TERMS::iterator firstTerm();
	typename TERMS::iterator lastTerm();//not really a term, but a node behind the last
	
	void destroy();//remove all terms
	void clean();//remove 0 terms
	


	T evaluate(const std::vector<T>& ass);


private:
	TERMS _polynomial;//the real container of the polynoimal

	int _lastvar;
	int _order;
	
};


#include "poly.cpp"


#endif