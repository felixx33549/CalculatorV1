#include "../include/stats.h"

#include "../include/addition.h"
#include "../include/division.h"

unsigned int minV(unsigned int n1, unsigned int n2)
{
	if (n1 < n2)	return n1;
	else			return n2;
}

unsigned int maxV(unsigned int n1, unsigned int n2)
{
	if (n1 > n2)	return n1;
	else			return n2;
}

void middleV(RealNum* num1, RealNum* num2, RealNum* num3)
{
	RealNum num;
	addition(num1, num2, &num);
	RealNum numN('2');
	division(&num, &numN, num3, 0xfffffffe);

	return;
}
