#include <iostream>
#include "func.hpp"
#include <fstream>
#include <string>

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

void Write(short cnt, std::string mas[2000], std::string ConsMas[2000], short UniqueCons[2000])
{
	for(short i = 0; i < cnt; i++)
	{
		std::cout << "<" << mas[i] << ">" << " " << "<" << ConsMas[i] << ">" << " " << UniqueCons[i] << std::endl;
	}
}

void clear_and_lower(short cnt, std::string mas[2000])
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

void OnlyCons(short cnt, std::string mas[2000], std::string ConsMas[2000])
{
	for(short i = 0; i < cnt; i++)
	{
		std::string a = mas[i];
		for(short j = 0; j < a.length();)
		{
			if((a[j] == 'a') || (a[j] == 'e') || (a[j] == 'i') || (a[j] == 'o') || (a[j] == 'u') || (a[j] == 'y'))
			{
				a.erase(j, 1);
			}
			else
			{
				j++;
			}
			ConsMas[i] = a;
		}
	}
}

void CountUniqueCons(short cnt, std::string mas[2000], std::string ConsMas[2000], short UniqueCons[2000])
{
	for(short i = 0; i < cnt; i++)
	{
		short cntOfUnique = 0;
		char letters[256] = {0};
		for(short j = 0; j < ConsMas[i].length(); j++)
		{
			letters[ConsMas[i][j]]++;
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