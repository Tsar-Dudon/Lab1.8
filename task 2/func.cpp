#include <iostream>
#include "func.hpp"
#include <fstream>
#include <string>

bool Read(short& cnt, std::string mas[5120])
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

void Write(short l, short n, std::string VowelsMas[5120], std::string NotDoubleVowels[5120])
{
	for(short i = 0; i < l; i++)
	{
		std::cout << VowelsMas[i] << std::endl;  
	}
	for(short i = 0; i < n; i++)
	{
		std::cout << NotDoubleVowels[i] << std::endl;  
	}
}

void clear_and_lower(short cnt, std::string mas[5120])
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
				mas[i][j] = tolower(mas[i][j]);
				j++;
			}
		}
	}
}

void HaveDoubleVowels(short cnt, short& l, short& n, std::string mas[5120], std::string VowelsMas[5120], std::string NotDoubleVowels[5120])
{
	l = 0;
	n = 0;
	for(short i = 0; i < cnt; i++)
	{
		char letters[256] = {0};
		short max = -1;
		for(short j = 0; j < mas[i].length(); j++)
		{
			if((mas[i][j] == 'a') || (mas[i][j] == 'e') || (mas[i][j] == 'i') || (mas[i][j] == 'o') || (mas[i][j] == 'u') || (mas[i][j] == 'y'))
			{
				letters[mas[i][j]]++;
			}
		}
		for(short k = 0; k < 256; k++)
		{
			if(letters[k] > max)
			{
				max = letters[k];
			}
		}
		if(max > 1)
		{
			VowelsMas[l] = mas[i];
			l++;
		}
		else
		{
			NotDoubleVowels[n] = mas[i];
			n++;
		}
	}
}

void Sort(short l, std::string VowelsMas[5120])
{
	for(short i = 0; i < l - 1; i++)
		for(short j = i + 1; j < l; j++)
		{
			if(VowelsMas[i] > VowelsMas[j])
			{
				std::swap(VowelsMas[i], VowelsMas[j]);
			}
		}
}

void Reverse(short n, std::string NotDoubleVowels[5120])
{
	for(short i = 0; i < n; i++)
	{
		std::string a = NotDoubleVowels[i];
		for(short j = 0; j < (a.length()/2); j++)
		{
			std::swap(a[j], a[a.length() - 1 - j]);
		}
		NotDoubleVowels[i] = a;
	}
}