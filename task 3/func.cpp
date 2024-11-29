#include <iostream>
#include "func.hpp"
#include <fstream>
#include <string>

bool ReadChars(short& cnt, char mas[10240])
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

bool ReadWords(short& cnt1, std::string mas[5120])
{
	std::ifstream in("input.txt"); //открытие файла
    cnt1 = 0;
	while(!in.eof())
	{
		in >> mas[cnt1];
		cnt1++;
	}
    return true;
}

void lower_and_count(short cnt, char mas[10240], char letters[256])
{
	for(short i = 0; i < cnt; i++)
	{
		mas[i] = tolower(mas[i]);
		letters[mas[i]]++;
	}
}

void findMax(char letters[256], char ValuesMaxes[8], char LettersMaxes[8])
{
	for(char i = 'a'; i < 'z' + 1; i++)
	{
		if(ValuesMaxes[0] < letters[i])
		{
			LettersMaxes[0] = i;
			ValuesMaxes[0] = letters[i];
		}
	}
	for(char i = 'a'; i < 'z' + 1; i++)
	{
		if((ValuesMaxes[1] < letters[i]) && (letters[i] <= ValuesMaxes[0]) && (i != LettersMaxes[0]))
		{
			LettersMaxes[1] = i;
			ValuesMaxes[1] = letters[i];
		}
	}
	for(char i = 'a'; i < 'z' + 1; i++)
	{
		if((ValuesMaxes[2] < letters[i]) && (letters[i] <= ValuesMaxes[1]) && (i != LettersMaxes[0]) && (i != LettersMaxes[1]))
		{
			LettersMaxes[2] = i;
			ValuesMaxes[2] = letters[i];
		}
	}
	for(char i = 'a'; i < 'z' + 1; i++)
	{
		if((ValuesMaxes[3] < letters[i]) && (letters[i] <= ValuesMaxes[2]) && (i != LettersMaxes[0]) && (i != LettersMaxes[1]) 
		&& (i != LettersMaxes[2]))
		{
			LettersMaxes[3] = i;
			ValuesMaxes[3] = letters[i];
		}
	}
	for(char i = 'a'; i < 'z' + 1; i++)
	{
		if((ValuesMaxes[4] < letters[i]) && (letters[i] <= ValuesMaxes[3]) && (i != LettersMaxes[0]) && (i != LettersMaxes[1]) 
		&& (i != LettersMaxes[2]) && (i != LettersMaxes[3]))
		{
			LettersMaxes[4] = i;
			ValuesMaxes[4] = letters[i];
		}
	}
	for(char i = 'a'; i < 'z' + 1; i++)
	{
		if((ValuesMaxes[5] < letters[i]) && (letters[i] <= ValuesMaxes[4]) && (i != LettersMaxes[0]) && (i != LettersMaxes[1]) 
		&& (i != LettersMaxes[2]) && (i != LettersMaxes[3]) && (i != LettersMaxes[4]))
		{
			LettersMaxes[5] = i;
			ValuesMaxes[5] = letters[i];
		}
	}
	for(char i = 'a'; i < 'z' + 1; i++)
	{
		if((ValuesMaxes[6] < letters[i]) && (letters[i] <= ValuesMaxes[5]) && (i != LettersMaxes[0]) && (i != LettersMaxes[1]) 
		&& (i != LettersMaxes[2]) && (i != LettersMaxes[3]) && (i != LettersMaxes[4]) && (i != LettersMaxes[5]))
		{
			LettersMaxes[6] = i;
			ValuesMaxes[6] = letters[i];
		}
	}
	for(char i = 'a'; i < 'z' + 1; i++)
	{
		if((ValuesMaxes[7] < letters[i]) && (letters[i] <= ValuesMaxes[6]) && (i != LettersMaxes[0]) && (i != LettersMaxes[1]) 
		&& (i != LettersMaxes[2]) && (i != LettersMaxes[3]) && (i != LettersMaxes[4]) && (i != LettersMaxes[5]) && (i != LettersMaxes[6]))
		{
			LettersMaxes[7] = i;
			ValuesMaxes[7] = letters[i];
		}
	}
}

void lower_words(short cnt1, std::string mas[5120])
{
	for(short i = 0; i < cnt1; i++)
	{
		for(short j = 0; j < mas[i].length(); j++)
		{
				mas[i][j] = tolower(mas[i][j]);
		}
	}
}

void is_needed(short cnt1, std::string mas[5120], char LetterMaxes[8])
{
	for(short i = 0; i < cnt1; i++)
	{
		char letters1[256] = {0};
		short sum = 0;
		for(short j = 0; j < mas[i].length(); j++)
		{
			if((mas[i][j] == LetterMaxes[0]) || (mas[i][j] == LetterMaxes[1]) || (mas[i][j] == LetterMaxes[2]) || (mas[i][j] == LetterMaxes[3]) ||
			(mas[i][j] == LetterMaxes[4]) || (mas[i][j] == LetterMaxes[5]) || (mas[i][j] == LetterMaxes[6]) || (mas[i][j] == LetterMaxes[7]))
			{
				letters1[mas[i][j]] = 1;
			}
		}
		for(int e = 0; e < 256; e++)
		{
			sum += letters1[e];
		}
		if(sum >= 5)
		{
			for(short j = 0; j < mas[i].length(); j++)
			{
				mas[i][j] = toupper(mas[i][j]);
			}
		}
	}
}

void Write(short cnt1, std::string masWords[5120])
{
	std::ofstream out("output.txt");
	for(short i = 0; i < cnt1; i++)
	{
		out << masWords[i] << std::endl;
	}
}
