#pragma once

#include <vector>

class RealNum
{
public:
	RealNum();
	RealNum(char n);
	RealNum(char c, char n);
	~RealNum();

	void printNum();
	void normNum();

	void setMinus(bool m);
	void setDigitVK(char d, unsigned int p);
	void setDigitNK(char d, unsigned int p);
	void delNum();

	bool getMinus();
	char getDigitVK(unsigned int p);
	char getDigitNK(unsigned int p);

	unsigned int getLengthVK();
	unsigned int getLengthNK();

private:
	char minus;
	std::vector<char> numvk;
	std::vector<char> numnk;
};
