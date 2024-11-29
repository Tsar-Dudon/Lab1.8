#pragma once
#include <string>

bool ReadChars(short& cnt, char mas[10240]);
void lower_and_count(short cnt, char mas[10240], char letters[256]);
void findMax(char letters[256], char ValuesMaxes[8], char LettersMaxes[8]);
bool ReadWords(short& cnt1, std::string mas[5120]);
void lower_words(short cnt1, std::string mas[5120]);
void is_needed(short cnt1, std::string mas[5120], char LetterMaxes[8]);
void Write(short cnt1, std::string masWords[5120]);