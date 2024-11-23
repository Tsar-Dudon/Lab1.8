#pragma once
#include <string>

bool Read(short& cnt, std::string mas[5120]);
void Write(short l, short n, std::string VowelsMas[5120], std::string NotDoubleVowels[5120]);
void clear_and_lower(short cnt, std::string mas[5120]);
void HaveDoubleVowels(short cnt, short& l, short& n, std::string mas[5120], std::string VowelsMas[5120], std::string NotDoubleVowels[5120]);
void Sort(short l, std::string VowelsMas[5120]);
void Reverse(short n, std::string NotDoubleVowels[5120]);