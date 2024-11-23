#include "func.hpp"
#include <iostream>
#include <string>
#include <fstream>

int main()
{	
	std::string mas[2001];
	short cnt;
	short UniqueCons[2001];

	if(!Read(cnt, mas))
	{
		return -1;
	}	

	clear_and_lower(cnt, mas);

	OnlyCons(cnt, mas, UniqueCons);

	Sort(cnt, mas, UniqueCons);

	Write(cnt, mas, UniqueCons);
	
	return 0;
}