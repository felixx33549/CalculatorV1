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

	RealNum num3;
	RealNum num4;
	RealNum num5;

	num3.setMinus(true);

	num3.setDigitVK(1, 0);
	num3.setDigitVK(2, 1);
	num3.setDigitVK(3, 2);

	num3.setDigitNK(4, 0);
	num3.setDigitNK(4, 0);
	num3.setDigitNK(4, 0);


	num4.setMinus(true);

	num4.setDigitVK(3, 0);
	num4.setDigitVK(3, 1);
	num4.setDigitVK(3, 2);

	num4.setDigitNK(3, 0);
	num4.setDigitNK(3, 0);
	num4.setDigitNK(3, 0);


	multiplication(&num3, &num4, &num5);

	num5.printNum();

	//system("PAUSE");
	return 0;
}
