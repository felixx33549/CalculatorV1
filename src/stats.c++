#include "../include/stats.h"

#include "../include/addition.h"

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

	unsigned int ue = 0;
	for (unsigned int i = num.getLengthVK(); i > 0; i--)
	{
		num3->setDigitVK(num.getDigitVK(i - 1) / 2 + ue, i - 1);
		if (num.getDigitVK(i - 1) % 2)
		{
			ue = 5;
		}
		else
		{
			ue = 0;
		}
	}
	for (unsigned int i = 0; i < num.getLengthNK(); i++)
	{
		num3->setDigitNK(num.getDigitNK(i) / 2 + ue, i);
		if (num.getDigitNK(i) % 2)
		{
			ue = 5;
		}
		else
		{
			ue = 0;
		}
	}
	if (ue)
	{
		num3->setDigitNK(ue, num3->getLengthNK());
	}

	return;
}
