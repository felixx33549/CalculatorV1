#include "../include/addition.h"

#include "../include/subtraction.h"
#include "../include/stats.h"
#include "../include/copyNum.h"

int addition(RealNum* num1, RealNum* num2, RealNum* num3)
{
	RealNum numE;

	if (!num1->getMinus() && num2->getMinus())
	{
		RealNum numZ;
		copyNum(num2, &numZ);
		numZ.setMinus(false);
		subtraction(num1, &numZ, &numE);

		copyNum(&numE, num3);
		return 1;
	}
	if (num1->getMinus() && !num2->getMinus())
	{
		RealNum numZ;
		copyNum(num1, &numZ);
		numZ.setMinus(false);
		subtraction(num2, &numZ, &numE);

		copyNum(&numE, num3);
		return 1;
	}
	
	numE.setMinus(num1->getMinus());

	char ue = '0';

	for (unsigned int i = maxV(num1->getLengthNK(), num2->getLengthNK()); i > 0; i--)
	{
		numE.setDigitNK(cadd(num1->getDigitNK(i - 1), num2->getDigitNK(i - 1), ue, &ue), i - 1);
	}

	for (unsigned int i = 0; i < maxV(num1->getLengthVK(), num2->getLengthVK()); i++)
	{
		numE.setDigitVK(cadd(num1->getDigitVK(i), num2->getDigitVK(i), ue, &ue), i);
	}
	if (ue != '0')
	{
		numE.setDigitVK(ue, numE.getLengthVK());
	}

	copyNum(&numE, num3);
	return 0;
}

char cadd(char a, char b, char ue1, char* ue2)
{
	*ue2 = ((a + b + ue1 - 144) / 10) + 48;

	return ((a + b + ue1 - 144) % 10) + 48;
}
