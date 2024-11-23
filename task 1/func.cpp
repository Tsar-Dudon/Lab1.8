#include <iostream>
#include "func.hpp"
#include <fstream>
#include <string>

bool Read(short& cnt, std::string mas[2001])
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

void Write(short cnt, std::string mas[2001], short UniqueCons[2001])
{
	std::ofstream out("output.txt");
	for(short i = 0; i < cnt; i++)
	{
		std::cout << "<" << mas[i] << ">" << " " << UniqueCons[i] << std::endl;
		if(mas[i] != mas[i + 1])
		{
			out << mas[i] << "(" << UniqueCons[i] << ")" << std::endl;
		}
	}
}

void clear_and_lower(short cnt, std::string mas[2001])
{
	for(short i = 0; i < cnt; i++)
	{
		for(short j = 0; j < mas[i].length();)
		{
			if(!isalpha(mas[i][j]))
			{
				mas[i].erase(j, 1);
			}
			else
			{
				j++;
			}
			mas[i][j] = tolower(mas[i][j]);
		}
	}
}

void OnlyCons(short cnt, std::string mas[2001], short UniqueCons[2001])
{
	for(short i = 0; i < cnt; i++)
	{
		short cntOfUnique = 0;
		char letters[256] = {0};
		for(short j = 0; j < mas[i].length(); j++)
		{
			if((mas[i][j] == 'a') || (mas[i][j] == 'e') || (mas[i][j] == 'i') || (mas[i][j] == 'o') || (mas[i][j] == 'u') || (mas[i][j] == 'y'))
			{
				continue;
			}
			else
			{
				letters[mas[i][j]]++;
			}
		}
		for(short k = 0; k < 256; k++)
		{
			if(letters[k] != 0)
			{
				cntOfUnique++;
			}
		UniqueCons[i] = cntOfUnique;
		}
	}
}

void Sort(short cnt, std::string mas[2001], short UniqueCons[2001])
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