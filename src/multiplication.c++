#include "../include/multiplication.h"

#include "../include/copyNum.h"
#include "../include/addition.h"
#include "../include/division.h"

void mul10(RealNum* num)
{
	RealNum num1;
	num1.setDigitVK(num->getDigitNK(0), 0);
	for (unsigned int i = 1; i < num->getLengthNK(); i++)
	{
		num1.setDigitNK(num->getDigitNK(i), i - 1);
	}
	for (unsigned int i = 0; i < num->getLengthVK(); i++)
	{
		num1.setDigitVK(num->getDigitVK(i), i + 1);
	}
	copyNum(&num1, num);

	return;
}

void mulWithDigit(RealNum* num, unsigned int n)
{
	RealNum numE;
	RealNum numZ;
	for (unsigned int i = 0; i < n; i++)
	{
		addition(num, &numE, &numZ);
		copyNum(&numZ, &numE);
	}
	
	copyNum(&numE, num);

	return;
}

int multiplication(RealNum* num1, RealNum* num2, RealNum* num3)
{
	num3->delNum();
	
	RealNum numE;
	RealNum numZE;
	RealNum numZ;
	RealNum numZZ;
	copyNum(num2, &numZ);
	numZ.setMinus(false);

	for (unsigned int i = 0; i < num1->getLengthVK(); i++)
	{
		copyNum(&numZ, &numZZ);
		mulWithDigit(&numZZ, num1->getDigitVK(i));
		addition(&numZZ, &numE, &numZE);
		copyNum(&numZE, &numE);
		mul10(&numZ);
	}

	copyNum(num2, &numZ);
	numZ.setMinus(false);

	for (unsigned int i = 0; i < num1->getLengthNK(); i++)
	{
		div10(&numZ);
		copyNum(&numZ, &numZZ);
		mulWithDigit(&numZZ, num1->getDigitNK(i));
		addition(&numZZ, &numE, &numZE);
		copyNum(&numZE, &numE);
	}
	
	copyNum(&numE, num3);
	if (num1->getMinus() != num2->getMinus())
	{
		num3->setMinus(true);
	}

	return 0;
}