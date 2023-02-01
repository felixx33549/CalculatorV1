#include "../include/addition.h"

#include "../include/subtraction.h"
#include "../include/stats.h"

int addition(RealNum* num1, RealNum* num2, RealNum* num3)
{
	num3->delNum();

	if (!num1->getMinus() && num2->getMinus())
	{
		num2->setMinus(false);
		subtraction(num1, num2, num3);
		num2->setMinus(true);

		return 1;
	}
	if (num1->getMinus() && !num2->getMinus())
	{
		num1->setMinus(false);
		subtraction(num2, num1, num3);
		num1->setMinus(true);

		return 1;
	}
	if (num1->getMinus() == num2->getMinus())
	{
		num3->setMinus(num1->getMinus());

		unsigned int ue = 0;

		for (unsigned int i = maxV(num1->getLengthNK(), num2->getLengthNK()); i > 0; i--)
		{
			num3->setDigitNK(num1->getDigitNK(i - 1) + num2->getDigitNK(i - 1) + ue, i - 1);
			ue = num3->getDigitNK(i - 1) / 10;
			num3->setDigitNK(num3->getDigitNK(i - 1) % 10, i - 1);
		}

		for (unsigned int i = 0; i < maxV(num1->getLengthVK(), num2->getLengthVK()); i++)
		{
			num3->setDigitVK(num1->getDigitVK(i) + num2->getDigitVK(i) + ue, i);
			ue = num3->getDigitVK(i) / 10;
			num3->setDigitVK(num3->getDigitVK(i) % 10, i);
		}
		if (ue)
		{
			num3->setDigitVK(ue, maxV(num1->getLengthVK(), num2->getLengthVK()));
		}
	}

	return 0;
}
