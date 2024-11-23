#include "func.hpp"
#include <iostream>
#include <string>
#include <fstream>

int main()
{	
	std::string mas[5120];//5120 потому что макс размер файла 10КБайт
	short cnt;
	std::string VowelsMas[5120];
	short l;
	std::string NotDoubleVowels[5120];
	short n;

	if(!Read(cnt, mas))
	{
		return -1;
	}	

	clear_and_lower(cnt, mas);

	HaveDoubleVowels(cnt, l, n, mas, VowelsMas, NotDoubleVowels);

	Sort(l, VowelsMas);

	Reverse(n, NotDoubleVowels);

	Write(l, n, VowelsMas, NotDoubleVowels);
	
	return 0;
}