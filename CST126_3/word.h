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
	std::string getWord() { return word; };
	void charUpdate(int i, char c) { word[i] = c; };
	char getWordC(int i) { return word[i]; };
	int updateWC(int i) { return wordOccurence = i; };
	void upWC() { wordOccurence++; };
	int getWC() { return wordOccurence; };
	void update(std::string s, int i) { word = s; wordOccurence = i; };
private:
	std::string word;
	int wordOccurence;
};

#endif /*TEXT_DATA*/