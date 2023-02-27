#include "../include/realNum.h"

#include <iostream>

RealNum::RealNum()
{
	this->minus = ' ';
	this->numvk.push_back('0');
}

RealNum::RealNum(char n)
{
	this->minus = ' ';
	this->numvk.push_back(n);
}

RealNum::RealNum(char c, char n)
{
	if (c == '-')
	{
		this->minus = '-';
	}
	else
	{
		this->minus = ' ';
	}
	this->numvk.push_back(n);
}

RealNum::~RealNum()
{
	//std::cout << "Destructor called for " << this->numvk[0] << std::endl;
	this->numvk.clear();
	this->numnk.clear();
}

void RealNum::printNum()
{
	if (this->minus == '-')
	{
		std::cout << '-';
	}
	for (unsigned int i = (unsigned int)this->numvk.size(); i > 0; i--)
	{
		std::cout << this->numvk[i - 1];
		if (i % 3 == 1 && i != 1)
		{
			std::cout << ".";
		}
	}
	if (this->numnk.size())
	{
		std::cout << ",";
		for (unsigned int i = 0; i < this->numnk.size(); i++)
		{
			std::cout << this->numnk[i];
		}
	}
	std::cout << std::endl;
	return;
}

void RealNum::normNum()
{
	for (unsigned int i = (unsigned int)this->numvk.size(); i > 0; i--)
	{
		if (this->numvk[i - 1] == '0')
		{
			this->numvk.pop_back();
		}
		else
		{
			break;
		}
	}
	for (unsigned int i = (unsigned int)this->numnk.size(); i > 0; i--)
	{
		if (this->numnk[i - 1] == '0')
		{
			this->numnk.pop_back();
		}
		else
		{
			break;
		}
	}

	if (this->numvk.empty())
	{
		this->numvk.push_back('0');
		if (this->numnk.empty()) this->minus = ' ';
	}
	return;
}

void RealNum::setMinus(bool m)
{
	if (m) this->minus = '-';
	else this->minus = ' ';

	return;
}

void RealNum::setDigitVK(char d, unsigned int p)
{
	if (p < this->numvk.size())
	{
		this->numvk[p] = d;
	}
	else
	{
		while (this->numvk.size() < p)
		{
			this->numvk.push_back('0');
		}
		this->numvk.push_back(d);
	}

	return;
}

void RealNum::setDigitNK(char d, unsigned int p)
{
	if (p < this->numnk.size())
	{
		this->numnk[p] = d;
	}
	else
	{
		while (this->numnk.size() < p)
		{
			this->numnk.push_back('0');
		}
		this->numnk.push_back(d);
	}

	return;
}

void RealNum::delNum()
{
	this->minus = ' ';
	this->numvk.clear();
	this->numnk.clear();
	return;
}

bool RealNum::getMinus()
{
	if (this->minus == '-')		return true;
	else						return false;
}

char RealNum::getDigitVK(unsigned int p)
{
	if (p < this->numvk.size())
	{
		return this->numvk[p];
	}
	else
	{
		return '0';
	}
}

char RealNum::getDigitNK(unsigned int p)
{
	if (p < this->numnk.size())
	{
		return this->numnk[p];
	}
	else
	{
		return '0';
	}
}

unsigned int RealNum::getLengthVK()
{
	return (unsigned int)this->numvk.size();
}

unsigned int RealNum::getLengthNK()
{
	return (unsigned int)this->numnk.size();
}
