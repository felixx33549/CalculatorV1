#include "../include/compareGreater.h"

#include "../include/stats.h"

int compareGreater(RealNum* num1, RealNum* num2)
{
	num1->normNum();
	num2->normNum();

	if (!num1->getMinus() && num2->getMinus())
	{
		return 1;
	}
	if (num1->getMinus() && !num2->getMinus())
	{
		return 2;
	}
	if (!num1->getMinus() && !num2->getMinus())
	{
		if (num1->getLengthVK() > num2->getLengthVK())
		{
			return 1;
		}
		if (num1->getLengthVK() < num2->getLengthVK())
		{
			return 2;
		}
		
		for (unsigned int i = num1->getLengthVK(); i > 0; i--)
		{
			if (num1->getDigitVK(i - 1) > num2->getDigitVK(i - 1))
			{
				return 1;
			}
			if (num1->getDigitVK(i - 1) < num2->getDigitVK(i - 1))
			{
				return 2;
			}
		}
		for (unsigned int i = 0; i < maxV(num1->getLengthNK() , num2->getLengthNK()); i++)
		{
			if (num1->getDigitNK(i) > num2->getDigitNK(i))
			{
				return 1;
			}
			if (num1->getDigitNK(i) < num2->getDigitNK(i))
			{
				return 2;
			}
		}
	}
	if (num1->getMinus() && num2->getMinus())
	{
		if (num1->getLengthVK() > num2->getLengthVK())
		{
			return 2;
		}
		if (num1->getLengthVK() < num2->getLengthVK())
		{
			return 1;
		}

		for (unsigned int i = num1->getLengthVK(); i > 0; i--)
		{
			if (num1->getDigitVK(i - 1) > num2->getDigitVK(i - 1))
			{
				return 2;
			}
			if (num1->getDigitVK(i - 1) < num2->getDigitVK(i - 1))
			{
				return 1;
			}
		}
		for (unsigned int i = 0; i < maxV(num1->getLengthNK(), num2->getLengthNK()); i++)
		{
			if (num1->getDigitNK(i) > num2->getDigitNK(i))
			{
				return 2;
			}
			if (num1->getDigitNK(i) < num2->getDigitNK(i))
			{
				return 1;
			}
		}
	}

	return 0;
}
