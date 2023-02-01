#include "../include/subtraction.h"

#include "../include/addition.h"
#include "../include/compareGreater.h"
#include "../include/stats.h"

int subtraction(RealNum* num1, RealNum* num2, RealNum* num3)
{
	if (num2->getMinus())
	{
		num2->setMinus(false);
		addition(num1, num2, num3);
		num2->setMinus(true);
		return 1;
	}
	if (num1->getMinus())
	{
		num1->setMinus(false);
		addition(num1, num2, num3);
		num1->setMinus(true);
		num3->setMinus(true);
		return 1;
	}

	if (compareGreater(num1, num2) == 0)
	{
		num3->delNum();
		num3->setDigitVK(0, 0);

		return 0;
	}
	if (compareGreater(num1, num2) == 1)
	{
		num3->delNum();

		unsigned int ue = 0;
		for (unsigned int i = maxV(num1->getLengthNK(), num2->getLengthNK()); i > 0; i--)
		{
			if (num1->getDigitNK(i - 1) < num2->getDigitNK(i - 1) + ue)
			{
				num3->setDigitNK(num1->getDigitNK(i - 1) + 10 - num2->getDigitNK(i - 1) - ue, i - 1);
				ue = 1;
			}
			else
			{
				num3->setDigitNK(num1->getDigitNK(i - 1) - num2->getDigitNK(i - 1) - ue, i - 1);
				ue = 0;
			}
		}
		for (unsigned int i = 0; i < maxV(num1->getLengthVK(), num2->getLengthVK()); i++)
		{
			if (num1->getDigitVK(i) < num2->getDigitVK(i) + ue)
			{
				num3->setDigitVK(num1->getDigitVK(i) + 10 - num2->getDigitVK(i) - ue, i);
				ue = 1;
			}
			else
			{
				num3->setDigitVK(num1->getDigitVK(i) - num2->getDigitVK(i) - ue, i);
				ue = 0;
			}
		}

		return 0;
	}
	if (compareGreater(num1, num2) == 2)
	{
		subtraction(num2, num1, num3);
		num3->setMinus(true);
		return 0;
	}

	return -1;
}
