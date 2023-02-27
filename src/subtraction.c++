#include "../include/subtraction.h"

#include "../include/addition.h"
#include "../include/compareGreater.h"
#include "../include/stats.h"
#include "../include/copyNum.h"

int subtraction(RealNum* num1, RealNum* num2, RealNum* num3)
{
	RealNum numE;

	if (num2->getMinus())
	{
		RealNum numZ;
		copyNum(num2, &numZ);
		numZ.setMinus(false);
		addition(num1, &numZ, &numE);
		copyNum(&numE, num3);
		return 1;
	}
	if (num1->getMinus())
	{
		RealNum numZ;
		copyNum(num1, &numZ);
		numZ.setMinus(false);
		addition(&numZ, num2, &numE);
		numE.setMinus(true);
		copyNum(&numE, num3);
		return 1;
	}

	if (compareGreater(num1, num2) == 0)
	{
		copyNum(&numE, num3);
		return 0;
	}
	if (compareGreater(num1, num2) == 1)
	{
		char ue = '0';

		for (unsigned int i = maxV(num1->getLengthNK(), num2->getLengthNK()); i > 0; i--)
		{
			numE.setDigitNK(cmin(num1->getDigitNK(i - 1), num2->getDigitNK(i - 1), ue, &ue), i - 1);
		}

		for (unsigned int i = 0; i < maxV(num1->getLengthVK(), num2->getLengthVK()); i++)
		{
			numE.setDigitVK(cmin(num1->getDigitVK(i), num2->getDigitVK(i), ue, &ue), i);
		}

		numE.normNum();

		copyNum(&numE, num3);
		return 0;
	}
	if (compareGreater(num1, num2) == 2)
	{
		subtraction(num2, num1, &numE);
		numE.setMinus(true);

		copyNum(&numE, num3);
		return 0;
	}

	return -1;
}

char cmin(char a, char b, char ue1, char* ue2)
{
	if (a < b + ue1 - 48)
	{
		*ue2 = '1';
		return a + 106 - b - ue1;
	}
	else
	{
		*ue2 = '0';
		return a + 96 - b - ue1;
	}
}
