#include <iostream>
#include <vector>

#include "../include/realNum.h"
#include "../include/compareGreater.h"
#include "../include/copyNum.h"
#include "../include/stats.h"
#include "../include/addition.h"
#include "../include/subtraction.h"
#include "../include/multiplication.h"
#include "../include/division.h"
#include "../include/squareRoot.h"
#include "../include/pi.h"

int main()
{
	/*--------------------SQRT(2)--------------------*/

	// RealNum num1(2);
	// RealNum num2;

	// unsigned int n;
	// unsigned int c;

	// //std::cout << "n = ";
	// //std::cin >> n;
	// n = 20;
	// //std::cout << "c = ";
	// //std::cin >> c;
	// c = 10;
	// std::cout << "sqrt(2) = " << std::endl;

	// squareRoot(&num1, &num2, n, c);

	// num2.printNum();

	/*--------------------PI--------------------*/

	RealNum numPI;

	unsigned int n = 20;
	unsigned int c = 4;

	if (n == 0)
	{
		std::cout << "n = ";
		std::cin >> n;
	}
	if (c == 0)
	{
		std::cout << "c = ";
		std::cin >> c;
	}
	
	
	
	std::cout << "pi = " << std::endl;

	calcPI(&numPI, c, n);

	numPI.printNum();

	// calcPIedge(&numPI, c, n);

	// numPI.printNum();

	/*--------------------etc--------------------*/

	// RealNum num3;
	// RealNum num4;
	// RealNum num5;

	// num3.setMinus(true);

	// num3.setDigitVK(1, 0);
	// num3.setDigitVK(2, 1);
	// num3.setDigitVK(3, 2);

	// num3.setDigitNK(4, 0);
	// num3.setDigitNK(5, 1);
	// num3.setDigitNK(6, 2);


	// num4.setMinus(true);

	// num4.setDigitVK(3, 0);
	// num4.setDigitVK(3, 1);
	// num4.setDigitVK(3, 2);

	// num4.setDigitNK(1, 0);
	// num4.setDigitNK(2, 1);
	// num4.setDigitNK(3, 2);


	// multiplication(&num3, &num4, &num5);

	// num5.printNum();

	// division(&num3, &num4, &num5, 10);

	// num5.printNum();

	//system("PAUSE");
	return 0;
}
