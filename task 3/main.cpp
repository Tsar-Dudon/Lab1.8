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
	std::string masWordsCopy[5120];
	char lettersInWords[5120][9] = {0};

	ReadWords(cnt1, masWords);

	for(short i = 0; i < cnt1; i++)
	{
		masWordsCopy[i] = masWords[i];
	}

	lower_words(cnt1, masWords);

	is_needed(cnt1, masWords, LettersMaxes, lettersInWords);

	/*for(short i = 0; i < cnt1; i++)
	{
		std::string a = masWords[i];
		a += "(";
		for(short e = 0; e < 8; e++)
		{
			a += lettersInWords[i][e];
		}
		a += ")";
		std::cout << a << std::endl;
	}*/

	std::ifstream in("input.txt");
	std::ofstream out("output.txt");
	short fuse = 0;
	while(!in.eof())
	{
		std::string s;
		getline(in, s);
		for(short i = fuse; i < cnt1; i++)
		{
			short g = s.find(masWordsCopy[i]);
			if(g < 0)
			{
				fuse = i;
				break;
			}
			s.replace(g, masWords[i].length(), masWords[i]);
			if(lettersInWords[i][8] == 1)
			{
				std::string w = "(";
				for(short e = 0; e < 8; e++)
				{
					w += lettersInWords[i][e];
				}
				w += ")";
				int h = g + masWords[i].length();
				s.insert(h, w);
			} 
		}
		out << s << std::endl;
	}

	return 0;
}