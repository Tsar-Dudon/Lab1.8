#include "func.hpp"
#include <iostream>
#include <string>
#include <fstream>

void Sort(short cnt, std::string mas[2000], short UniqueCons[2000])
{
	for(short i = 0; i < cnt - 1; i++)
		for(short j = i + 1; j < cnt; j++)
		{
			if((UniqueCons[j] > UniqueCons[i]) || ((UniqueCons[j] == UniqueCons[i]) && (mas[i] < mas[j])))
			{
				std::swap(UniqueCons[i], UniqueCons[j]);
				std::swap(mas[i], mas[j]);
			}
		}
}

int main()
{	
	std::string mas[2000];
	short cnt;
	std::string ConsMas[2000];
	short UniqueCons[2000];

	if(!Read(cnt, mas))
	{
		return -1;
	}	

	clear_and_lower(cnt, mas);

	OnlyCons(cnt, mas, ConsMas);

	CountUniqueCons(cnt, mas, ConsMas, UniqueCons);

	Sort(cnt, mas, UniqueCons);

	Write(cnt, mas, ConsMas, UniqueCons);
	
	return 0;
}