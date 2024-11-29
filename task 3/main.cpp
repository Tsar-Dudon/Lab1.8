#include "func.hpp"
#include <iostream>
#include <string>
#include <fstream>

int main()
{	
	short cnt;
	char masChars[10240];
	char letters[256] = {0};
	char ValuesMaxes[8] = {CHAR_MIN};
	char LettersMaxes[8] = {CHAR_MIN};

	if(!ReadChars(cnt, masChars))
	{
		return -1;
	}	

	lower_and_count(cnt, masChars, letters);

	findMax(letters, ValuesMaxes, LettersMaxes);

	short cnt1;
	std::string masWords[5120];

	ReadWords(cnt1, masWords);

	lower_words(cnt1, masWords);

	is_needed(cnt1, masWords, LettersMaxes);

	for(int i = 0; i < cnt1; i++)
	{
		std::cout << masWords[i] << std::endl;
	}

	Write(cnt1, masWords);

	return 0;
}