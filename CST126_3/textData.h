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
	void printWord() { std::cout << word << std::endl; };
	std::string getWord() { return word; };
	void charUpdate(int i, char c) { word[i] = c; };
	void printWordC(int i) { std::cout << word[i] << std::endl; };
	char getWordC(int i) { return word[i]; };
	int updateWC(int i) { return wordOccurence = i; };
	void upWC() { wordOccurence++; };
	void printWC() { std::cout << wordOccurence << std::endl; };
	int getWC() { return wordOccurence; };
private:
	std::string word;
	int wordOccurence;
};

#endif /*TEXT_DATA*/