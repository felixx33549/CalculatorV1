#include "../include/pi.h"

#include "../include/copyNum.h"
#include "../include/compareGreater.h"
#include "../include/addition.h"
#include "../include/multiplication.h"
#include "../include/division.h"

int calcPI(RealNum* pi, unsigned int c, unsigned int n)
{
	RealNum num('1');
	RealNum num2('2');
	for (unsigned int i = 0; i < c; i++)
	{
		division(&num, &num2, &num, 0xfffffffe);
	}
	
	RealNum num1('1');

	RealNum numC;
	RealNum numN;

	RealNum numX;
	RealNum numY;
	RealNum numX2;
	RealNum numY2;
	RealNum numS;

	while (compareGreater(&numX, &num1) == 2)
	{
		while (compareGreater(&numY, &num1) == 2)
		{
			multiplication(&numX, &numX, &numX2);
			multiplication(&numY, &numY, &numY2);
			addition(&numX2, &numY2, &numS);
			if (compareGreater(&numS, &num1) == 2)
			{
				addition(&numC, &num1, &numC);
			}
			addition(&numN, &num1, &numN);
			
			addition(&numY, &num, &numY);
		}
		numY.delNum();
		numY.normNum();

		addition(&numX, &num, &numX);
	}
	
	

	mulWithDigit(&numC, 4);
	division(&numC, &numN, pi, n);

	return 0;
}

int calcPIedge(RealNum* pi, unsigned int c, unsigned int n)
{
	RealNum num('1');
	RealNum num2('2');
	for (unsigned int i = 0; i < c; i++)
	{
		division(&num, &num2, &num, 0xfffffffe);
	}
	
	RealNum num1('1');

	RealNum numC;
	RealNum numN;

	RealNum numX;
	RealNum numY;
	RealNum numX2;
	RealNum numY2;
	RealNum numS;

	while (compareGreater(&numX, &num1) != 1)
	{
		while (compareGreater(&numY, &num1) != 1)
		{
			multiplication(&numX, &numX, &numX2);
			multiplication(&numY, &numY, &numY2);
			addition(&numX2, &numY2, &numS);
			if (compareGreater(&numS, &num1) != 1)
			{
				addition(&numC, &num1, &numC);
			}
			addition(&numN, &num1, &numN);
			
			addition(&numY, &num, &numY);
		}
		numY.delNum();
		numY.normNum();

		addition(&numX, &num, &numX);
	}
	
	

	mulWithDigit(&numC, 4);
	division(&numC, &numN, pi, n);

	return 0;
}
