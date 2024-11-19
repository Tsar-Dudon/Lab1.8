#include "func.hpp"
#include <iostream>
#include <string>
#include <fstream>

int main()
{	
	std::string mas[2000];
	short cnt;

	if(!Read(cnt, mas))
	{
		return -1;
	}

	Write(cnt, mas);
	
	return 0;
}