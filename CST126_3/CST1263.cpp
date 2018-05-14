// fstream code has been constructed using CST126_02 / Professor sample as a template.
// Video found at https://www.youtube.com/watch?v=Iho2EdJgusQ has helped me understand how to read from files
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

#include "textData.h"

bool openFile(std::ifstream & inputFile);
int getSize(std::ifstream & inputFile);
void fillClass(std::ifstream & inputFile, textData * tPtr, int size);

int main()
{
	std::ifstream textFile;

	if (openFile(textFile))
	{
		int wordCount{ getSize(textFile) };

		textData * textDataPtr{ nullptr };
		textDataPtr = new textData[wordCount];

		fillClass(textFile, textDataPtr, wordCount);

		delete[] textDataPtr;
		textDataPtr = nullptr;
	}
		
    return 0;
}

bool openFile(std::ifstream & inputFile)
{
	std::string fileName;

	std::cout << "Please enter the input file name including extension : ";
	std::cin >> fileName;

	inputFile.open(fileName);
	if (inputFile.fail())
	{
		std::cout << "There has been an error trying to open the file " << fileName;
		return false;
	}
	else
	{
		return true;
	}
}

int getSize(std::ifstream & inputFile)
{
	int wordCount{ 0 };

	inputFile >> wordCount;

	return wordCount;
}

void fillClass(std::ifstream & inputFile, textData * tPtr, int size)
{
	std::string word;

	for (int i{ 0 }; i < size && !inputFile.eof(); i++)
	{
		inputFile >> word;
		
	}
}
