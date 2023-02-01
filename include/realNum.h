#pragma once

#include <vector>

class RealNum
{
public:
	RealNum();
	RealNum(unsigned int n);
	RealNum(char c, unsigned int n);
	~RealNum();

	void printNum();
	void normNum();

	void setMinus(bool m);
	void setDigitVK(unsigned int d, unsigned int p);
	void setDigitNK(unsigned int d, unsigned int p);
	void delNum();

	bool getMinus();
	unsigned int getDigitVK(unsigned int p);
	unsigned int getDigitNK(unsigned int p);

	unsigned int getLengthVK();
	unsigned int getLengthNK();

private:
	char minus;
	std::vector<unsigned int> numvk;
	std::vector<unsigned int> numnk;
};
