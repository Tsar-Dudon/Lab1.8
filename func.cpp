#include <iostream>
#include "func.hpp"
#include <fstream>

bool Read(short& cnt, std::string mas[2000])
{
	std::ifstream in("input.txt"); //открытие файла
	if(!in.is_open()) //Проверка существования файла
	{
		std::cerr << "File error" << std::endl;
		return false;
	}

    cnt = 0;
	while(!in.eof())
	{
		in >> mas[cnt];
		cnt++;
	}
    return true;
}

void Write(short cnt, std::string mas[2000])
{
	for(short i = 0; i < cnt; i++)
	{
		std::cout << "<" << mas[i] << ">" << std::endl;
	}
}