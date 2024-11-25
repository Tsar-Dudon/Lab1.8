#include <iostream>
#include "func.hpp"
#include <fstream>
#include <string>

bool Read(short& cnt, char mas[10240])
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

void Write(short cnt, char mas[10240])
{
	std::ofstream out("output.txt");
	for(short i = 0; i < cnt; i++)
	{
		std::cout << "<" << mas[i] << ">" << std::endl;
		out << mas[i] << std::endl;
	}
}

void lower_and_count(short cnt, char mas[10240], char letters[256])
{
	for(short i = 0; i < cnt; i++)
	{
		mas[i] = tolower(mas[i]);
		letters[mas[i]]++;
	}
}
