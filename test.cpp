#include "poly.h"
#include <vector>

int main()
{
	poly<float> p1;
	poly<float> p2;
	poly<float> p3;
	std::vector<int> v1(3,2);
	std::vector<int> v2(3,2);
	std::vector<int> v3(3,5);

	p1.addTerm(v1,3.0);
	p2.addTerm(v2,4.0);


	printf("term1=%f\n",p1.getTerm(v1));
	printf("%d\n",p1.lastVar());
	printf("term2=%f\n",p2.getTerm(v2));
	printf("%d\n",p2.lastVar());

	p3 = p1-p2+p1;

	printf("term3=%f\n",p3.getTerm(v2));
	printf("%d\n",p3.lastVar());

	p3 = p3*7;

	printf("term3=%f\n",p3.getTerm(v2));
	printf("%d\n",p3.lastVar());
	
	p3.addTerm(v3,0);

	printf("term3=%f\n",p3.getTerm(v3));
	printf("%d\n",p3.lastVar());

	p3.destroy();
	p3.clean();

	printf("term3=%f\n",p3.getTerm(v3));
	printf("%d\n",p3.lastVar());
	return 0;
}