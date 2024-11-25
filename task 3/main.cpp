#include "func.hpp"
#include <iostream>
#include <string>
#include <fstream>

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

int main()
{	
	short cnt;
	char masChars[10240];
	char letters[256] = {0};
	char ValuesMaxes[8] = {CHAR_MIN};
	char LettersMaxes[8] = {CHAR_MIN};

	if(!Read(cnt, masChars))
	{
		return -1;
	}	

	lower_and_count(cnt, masChars, letters);

	findMax(letters, ValuesMaxes, LettersMaxes);

	for(short i = 0; i < 8; i++)
		std::cout << LettersMaxes[i] << " " << (int)ValuesMaxes[i] << std::endl;

	return 0;
}