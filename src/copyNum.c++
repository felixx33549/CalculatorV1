#include "../include/copyNum.h"

void copyNum(RealNum* num1, RealNum* num2)
{
	num2->delNum();
	num2->setMinus(num1->getMinus());
	for (unsigned int i = 0; i < num1->getLengthNK(); i++)
	{
		num2->setDigitNK(num1->getDigitNK(i), i);
	}
	for (unsigned int i = 0; i < num1->getLengthVK(); i++)
	{
		num2->setDigitVK(num1->getDigitVK(i), i);
	}

	return;
}
