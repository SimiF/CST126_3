#include "stdafx.h"
#include <string>
#include <iostream>

#ifndef TEXT_DATA
#define TEXT_DATA

class textData
{
public:
	textData(){ word = '\0'; wordOccurence = 0; };
	void wordUpdate(std::string w) { word = w; };
	void getWord() { std::cout << word << std::endl; };
	void getWordCP(int i) { std::cout << word[i] << std::endl; };
	char getWordC(int i) { return word[i]; };
	void charUpdate(int i, char c) { word[i] = c; };
private:
	std::string word;
	int wordOccurence;
};

#endif /*TEXT_DATA*/