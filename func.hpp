#pragma once
#include <string>

bool Read(short& cnt, std::string mas[2000]);
void Write(short cnt, std::string mas[2000], std::string ConsMas[2000], short UniqueCons[2000]);
void clear_and_lower(short cnt, std::string mas[2000]);
void OnlyCons(short cnt, std::string mas[2000], std::string ConsMas[2000]);
void CountUniqueCons(short cnt, std::string mas[2000], std::string ConsMas[2000], short UniqueCons[2000]);