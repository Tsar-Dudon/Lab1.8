#include "func.hpp"
#include <iostream>
#include <string>
#include <fstream>

int main()
{	
	std::string mas[5120];//5120 потому что макс размер файла 10КБайт
	short cnt;

	if(!Read(cnt, mas))
	{
		return -1;
	}	

	clear_and_lower(cnt, mas);

	Write(cnt, mas);
	
	return 0;
}