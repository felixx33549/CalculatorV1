#include "../include/pi.h"

#include "../include/copyNum.h"
#include "../include/compareGreater.h"
#include "../include/addition.h"
#include "../include/multiplication.h"
#include "../include/division.h"

int calcPI(RealNum* pi, unsigned int c, unsigned int n)
{
	RealNum num(1);
	RealNum num2(2);
	RealNum num2Z;
	for (unsigned int i = 0; i < c; i++)
	{
		division(&num, &num2, &num2Z, 1000);
		copyNum(&num2Z, &num);
	}
	
	RealNum num1(1);

	RealNum numC;
	RealNum numN;

	RealNum numX;
	RealNum numY;
	RealNum numZ;
	RealNum numZX;
	RealNum numZY;
	RealNum numZZ;

	while (compareGreater(&numX, &num1) == 2)
	{
		while (compareGreater(&numY, &num1) == 2)
		{
			multiplication(&numX, &numX, &numZX);
			multiplication(&numY, &numY, &numZY);
			addition(&numZX, &numZY, &numZZ);
			if (compareGreater(&numZZ, &num1) == 2)
			{
				addition(&numC, &num1, &numZ);
				copyNum(&numZ, &numC);
			}
			addition(&numN, &num1, &numZ);
			copyNum(&numZ, &numN);
			
			addition(&numY, &num, &numZ);
			copyNum(&numZ, &numY);
		}
		numY.delNum();
		numY.setDigitVK(0, 0);

		addition(&numX, &num, &numZ);
		copyNum(&numZ, &numX);
	}
	
	

	mulWithDigit(&numC, 4);
	division(&numC, &numN, pi, n);

	return 0;
}

int calcPIedge(RealNum* pi, unsigned int c, unsigned int n)
{
	RealNum num(1);
	RealNum num2(2);
	RealNum num2Z;
	for (unsigned int i = 0; i < c; i++)
	{
		division(&num, &num2, &num2Z, 1000);
		copyNum(&num2Z, &num);
	}
	
	RealNum num1(1);

	RealNum numC;
	RealNum numN;

	RealNum numX;
	RealNum numY;
	RealNum numZ;
	RealNum numZX;
	RealNum numZY;
	RealNum numZZ;

	while (compareGreater(&numX, &num1) != 1)
	{
		while (compareGreater(&numY, &num1) != 1)
		{
			multiplication(&numX, &numX, &numZX);
			multiplication(&numY, &numY, &numZY);
			addition(&numZX, &numZY, &numZZ);
			if (compareGreater(&numZZ, &num1) != 1)
			{
				addition(&numC, &num1, &numZ);
				copyNum(&numZ, &numC);
			}
			addition(&numN, &num1, &numZ);
			copyNum(&numZ, &numN);
			
			addition(&numY, &num, &numZ);
			copyNum(&numZ, &numY);
		}
		numY.delNum();
		numY.setDigitVK(0, 0);

		addition(&numX, &num, &numZ);
		copyNum(&numZ, &numX);
	}
	
	

	mulWithDigit(&numC, 4);
	division(&numC, &numN, pi, n);

	return 0;
}
