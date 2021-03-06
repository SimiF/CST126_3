/* 
-  fstream code has been constructed using CST126_02 / Professor sample as a template.
-  Video found at https://www.youtube.com/watch?v=Iho2EdJgusQ has helped me understand how to read from files
-  Website http://www.cplusplus.com/ has helped me understand the conversion from uppercase to lowercase
-  Website http://www.programmingincpp.com/string-erase-function.html has helped me understand how to 
   erase characters bubblesort has been constructed using Professor's sample as a guide
*/
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <iomanip>

#include "word.h"

bool openFile(std::ifstream & inputFile);
int getSize(std::ifstream & inputFile);
void fillClass(std::ifstream & inputFile, textData * tPtr, const int & size);
void editClass(textData * tPtr, const int & size);
void countWords(textData * tPtr, const int & size);
void sortWords(textData * tPtr, const int & size);
void printTopTen(textData * tPtr);

int main()
{
	std::ifstream textFile;

	if (openFile(textFile))
	{
		const int wordCount{ getSize(textFile) };

		textData * tPtr{ nullptr };
		tPtr = new textData[wordCount];

		fillClass(textFile, tPtr, wordCount);
		editClass(tPtr, wordCount);
		countWords(tPtr, wordCount);
		sortWords(tPtr, wordCount);
		printTopTen(tPtr);

		std::cout << std::endl;

		delete[] tPtr;
		tPtr = nullptr;
	}
		
    return 0;
}

bool openFile(std::ifstream & inputFile)
{
	std::string fileName{ '\0' };

	std::cout << "Please enter the input file name including extension : ";
	std::cin >> fileName;
	std::cout << std::endl;

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

void fillClass(std::ifstream & inputFile, textData * tPtr, const int & size)
{
	std::string word;

	for (int i{ 0 }; i < size && !inputFile.eof(); i++)
	{
		inputFile >> word;
		tPtr[i].wordUpdate(word);
	}
}

void editClass(textData * tPtr, const int & size)
{
	std::locale const loc;
	for (int i{ 0 }; i < size; i++)
	{
		int j{ 0 };
		for (j; tPtr[i].getWordC(j) != '\0'; j++)
		{
			if (ispunct(tPtr[i].getWordC(j)) && tPtr[i].getWordC(j) != '-')
			{
				tPtr[i].wordUpdate(tPtr[i].getWord().erase(j, 1));
				if (j != 0)
				{
					j -= 1;
				}
			}
			if (std::isupper(tPtr[i].getWordC(j), loc))
			{
				tPtr[i].charUpdate(j, std::tolower(tPtr[i].getWordC(j), loc));
			}
		}
	}
}

void countWords(textData * tPtr, const int & size)
{
	for (int i{ 0 }; i < size; i++)
	{
		if (tPtr[i].getWC() == 0)
		{
			for (int j{ 0 }; j < size; j++)
			{
				if (tPtr[i].getWord() == tPtr[j].getWord())
				{
					tPtr[i].upWC();
					tPtr[j].updateWC(1);
				}
			}
		}
	}
}

void sortWords(textData * tPtr, const int & size)
{
	for (int i{ 0 }; i < size - 1; i++)
	{
		for (int j{ 0 }; j < size - i - 1; j++)
		{
			if (tPtr[j + 1].getWC() > tPtr[j].getWC())
			{
				textData temp;
				temp.update(tPtr[j].getWord(), tPtr[j].getWC());
				tPtr[j].update(tPtr[j + 1].getWord(), tPtr[j + 1].getWC());
				tPtr[j + 1].update(temp.getWord(), temp.getWC());
			}
		}
	}
}

void printTopTen(textData * tPtr)
{
	for (int i{ 0 }; i < 10; i++)
	{
		std::cout << std::setw(16) << std::right << tPtr[i].getWord() << " " << std::left << tPtr[i].getWC() << std::endl;
	}
}