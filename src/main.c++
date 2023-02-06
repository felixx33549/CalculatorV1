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
	RealNum num1(2);
	RealNum num2;

	unsigned int n;
	unsigned int c;

	std::cout << "n = ";
	std::cin >> n;
	std::cout << "c = ";
	std::cin >> c;
	std::cout << "sqrt(2) = " << std::endl;

	squareRoot(&num1, &num2, n, c);

	num2.printNum();

	//system("PAUSE");
	return 0;
}
