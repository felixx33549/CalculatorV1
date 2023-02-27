#include "../include/pi.h"

#include "../include/copyNum.h"
#include "../include/compareGreater.h"
#include "../include/addition.h"
#include "../include/multiplication.h"
#include "../include/division.h"
#include <thread>

int calcPI(RealNum* pi, unsigned int c, unsigned int n)
{
	RealNum num('1');
	RealNum num2('2');
	for (unsigned int i = 0; i < c; i++)
	{
		division(&num, &num2, &num, 0xfffffffe);
	}
	
	RealNum num1('1');

	RealNum numC;
	RealNum numN;

	RealNum numX;
	RealNum numY;
	RealNum numX2;
	RealNum numY2;
	RealNum numS;

	while (compareGreater(&numX, &num1) == 2)
	{
		while (compareGreater(&numY, &num1) == 2)
		{
			multiplication(&numX, &numX, &numX2);
			multiplication(&numY, &numY, &numY2);
			addition(&numX2, &numY2, &numS);
			if (compareGreater(&numS, &num1) == 2)
			{
				addition(&numC, &num1, &numC);
			}
			addition(&numN, &num1, &numN);
			
			addition(&numY, &num, &numY);
		}
		numY.delNum();
		numY.normNum();

		addition(&numX, &num, &numX);
	}
	
	

	mulWithDigit(&numC, 4);
	division(&numC, &numN, pi, n);

	return 0;
}

int calcPIedge(RealNum* pi, unsigned int c, unsigned int n)
{
	RealNum num('1');
	RealNum num2('2');
	for (unsigned int i = 0; i < c; i++)
	{
		division(&num, &num2, &num, 0xfffffffe);
	}
	
	RealNum num1('1');

	RealNum numC;
	RealNum numN;

	RealNum numX;
	RealNum numY;
	RealNum numX2;
	RealNum numY2;
	RealNum numS;

	while (compareGreater(&numX, &num1) != 1)
	{
		while (compareGreater(&numY, &num1) != 1)
		{
			multiplication(&numX, &numX, &numX2);
			multiplication(&numY, &numY, &numY2);
			addition(&numX2, &numY2, &numS);
			if (compareGreater(&numS, &num1) != 1)
			{
				addition(&numC, &num1, &numC);
			}
			addition(&numN, &num1, &numN);
			
			addition(&numY, &num, &numY);
		}
		numY.delNum();
		numY.normNum();

		addition(&numX, &num, &numX);
	}
	
	

	mulWithDigit(&numC, 4);
	division(&numC, &numN, pi, n);

	return 0;
}

int calcPIvector(RealNum* pi, unsigned int c, unsigned int n)
{
	RealNum num('1');
	RealNum num2('2');
	for (unsigned int i = 0; i < c; i++)
	{
		division(&num, &num2, &num, 0xfffffffe);
	}
	
	RealNum num1('1');

	RealNum numC;
	RealNum numN;

	RealNum numX;

	std::vector<RealNum> C;
	std::vector<RealNum> N;
	std::vector<RealNum> X2;
	std::vector<RealNum> S;

	std::vector<std::thread> vecOfThreads;

	while (compareGreater(&numX, &num1) == 2)
	{
		RealNum num0;
		C.push_back(num0);
		N.push_back(num0);
		X2.push_back(num0);
		S.push_back(num);
		multiplication(&numX, &numX, &X2.back());

		vecOfThreads.push_back(std::thread(calcPIv, &S.back(), &X2.back(), &C.back(), &N.back()));
		vecOfThreads.back().join();
		//calcPIv(&num, &X2.back(), &C.back(), &N.back());

		addition(&numX, &num, &numX);
	}
	// for (std::thread & th : vecOfThreads)
	// {
	// 	th.join();
	// }
	


	while (C.size())
	{
		addition(&C.back(), &numC, &numC);
		C.back().delNum();
		C.pop_back();
	}
	while (N.size())
	{
		addition(&N.back(), &numN, &numN);
		N.back().delNum();
		N.pop_back();
	}
	while (X2.size())
	{
		X2.back().delNum();
		X2.pop_back();
	}
	
	
	mulWithDigit(&numC, 4);
	division(&numC, &numN, pi, n);

	return 0;
}

void calcPIv(RealNum* w, RealNum* numX2, RealNum* C, RealNum* N)
{
	RealNum num1('1');
	RealNum numY;
	RealNum numY2;
	RealNum S;

	while (compareGreater(&numY, &num1) == 2)
	{
		multiplication(&numY, &numY, &numY2);
		addition(numX2, &numY2, &S);
		if (compareGreater(&S, &num1) == 2)
		{
			addition(C, &num1, C);
		}
		addition(N, &num1, N);

		addition(&numY, w, &numY);
	}

	return;
}
