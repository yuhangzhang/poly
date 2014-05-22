#include <map>
#include <vector>
//#include <Eigen/core>
//#include <Eigen/Dense>
//#include <Eigen/SparseCore>

using namespace std;

#ifndef _POLY_H_
#define _POLY_H_

template<class T>
class poly
{
public:
	typedef typename std::map<int,T> TERMS;
	poly(int numvar, int order);
	int numterm();//return the number of terms with nonezero parameters
private:
	int combination(int numvar, int order);//return the maximum number of terms in this polynomial
	int termid(const vector<int>& vars);//return the serial number of the input term in this polynomial
	TERMS _polynomial;//the real container of the polynoimal

	int _numvar;
	int _order;
	
};


#include "poly.cpp"


#endif