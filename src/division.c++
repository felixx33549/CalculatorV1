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
	num3->delNum();

	RealNum numZ;
	RealNum numZZ;
	copyNum(num1, &numZ);
	numZ.setMinus(false);
	RealNum numN;
	copyNum(num2, &numN);
	numN.setMinus(false);
	RealNum numC(1);
	RealNum numE;

	unsigned int s = 0;

	while (s < n + 1)
	{
		while (compareGreater(&numZ, &numN) == 1)
		{
			subtraction(&numZ, &numN, &numZZ);
			copyNum(&numZZ, &numZ);
			addition(&numC, &numE, num3);
			copyNum(num3, &numE);
		}
		if (compareGreater(&numZ, &numN) == 0)
		{
			addition(&numC, &numE, num3);
			if (num1->getMinus() != num2->getMinus())
			{
				num3->setMinus(true);
			}
			return 0;
		}

		s++;
		div10(&numC);
		div10(&numN);
	}

	if (num1->getMinus() != num2->getMinus())
	{
		num3->setMinus(true);
	}

	return 1;
}
