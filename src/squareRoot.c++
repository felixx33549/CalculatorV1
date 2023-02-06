#include "../include/squareRoot.h"

#include "../include/division.h"
#include "../include/stats.h"
#include "../include/copyNum.h"

int squareRoot(RealNum* num, RealNum* numE, unsigned int n, unsigned int c)
{
	RealNum num1(1);
	RealNum num2;

	for (unsigned int i = 0; i < c; i++)
	{
		//num1.printNum();
		division(num, &num1, &num2, n + 1);
		middleV(&num1, &num2, &num1);
		num1.normNum();
		num2.normNum();
	}
	//num1.printNum();

	copyNum(&num1, numE);

	return 0;
}
