#include "../include/division.h"

#include "../include/copyNum.h"
#include "../include/compareGreater.h"
#include "../include/subtraction.h"
#include "../include/addition.h"

void div10(RealNum* num)
{
	RealNum num1;
	num1.setDigitNK(num->getDigitVK(0), 0);
	for (unsigned int i = 1; i < num->getLengthVK(); i++)
	{
		num1.setDigitVK(num->getDigitVK(i), i - 1);
	}
	for (unsigned int i = 0; i < num->getLengthNK(); i++)
	{
		num1.setDigitNK(num->getDigitNK(i), i + 1);
	}
	copyNum(&num1, num);

	return;
}

int division(RealNum* num1, RealNum* num2, RealNum* num3, unsigned int n)
{
	RealNum numZ;
	copyNum(num1, &numZ);
	numZ.setMinus(false);
	RealNum numN;
	copyNum(num2, &numN);
	numN.setMinus(false);
	RealNum numC('1');
	RealNum numE;

	for (unsigned int s = 0; s < n + 1; s++)
	{
		while (compareGreater(&numZ, &numN) == 1)
		{
			subtraction(&numZ, &numN, &numZ);
			addition(&numC, &numE, &numE);
		}
		if (compareGreater(&numZ, &numN) == 0)
		{
			addition(&numC, &numE, &numE);
			if (num1->getMinus() != num2->getMinus())
			{
				numE.setMinus(true);
			}
			copyNum(&numE, num3);
			return 0;
		}

		div10(&numC);
		div10(&numN);
	}

	if (num1->getMinus() != num2->getMinus())
	{
		numE.setMinus(true);
	}

	copyNum(&numE, num3);
	return 1;
}
