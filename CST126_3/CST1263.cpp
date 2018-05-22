/* 
-  fstream code has been constructed using CST126_02 / Professor sample as a template.
-  Video found at https://www.youtube.com/watch?v=Iho2EdJgusQ has helped me understand how to read from files
-  Website http://www.cplusplus.com/ has helped me understand the conversion from uppercase to lowercase
-  Website http://www.programmingincpp.com/string-erase-function.html has helped me understand how to 
   erase characters bubblesort has been constructed using Professor's sample as a guide
*/
#include "stdafx.h"
#include <cassert>
#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <iomanip>

#include "word.h"

bool openFile(std::ifstream & inputFile) // I wouldn't combine the data entry with the opening of a stream. I would just return the string and open it when returned. Keep your tasks in separate functions. 
{
	bool result{ false };
	std::string fileName; // default constructor is an empty string. No need to initialize. 

	std::cout << "Please enter the input file name including extension : ";
	std::cin >> fileName;
	std::cout << std::endl;

	inputFile.open(fileName);
	if (!inputFile.good())
	{
		std::cout << "There has been an error trying to open the file " << fileName;
	}
	else
	{
		result = true;
	}
	return result; // Try to stick to a single return. 
}

int getSize(std::ifstream & inputFile)
{
	int wordCount{ 0 };

	inputFile >> wordCount;

	return wordCount;
}

void fillClass(std::ifstream & inputFile, textData * const tPtr, const int & size)
{
	std::string word;

	for (int i{ 0 }; i < size && !inputFile.eof(); i++)
	{
		inputFile >> word;
		assert(inputFile.good());
		tPtr[i].wordUpdate(word);
	}
}

void editClass(textData * const tPtr, const int & size)
{
	std::locale const loc;
	for (int i{ 0 }; i < size; i++)
	{
		for (int j{0}; tPtr[i].getWordC(j) != '\0'; j++)
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

void countWords(textData * const tPtr, const int & size)
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

void sortWords(textData * const tPtr, const int & size)
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

void printTopTen(textData const * const tPtr)
{
	for (int i{ 0 }; i < 10; i++)
	{
		std::cout << std::setw(16) << std::right << tPtr[i].getWord() << " " << std::left << tPtr[i].getWC() << std::endl;
	}
}

int main() // Moved to end of file so the defintions can also be used as declarations. 
{
	std::ifstream textFile;

	if (openFile(textFile))
	{
		const int wordCount{ getSize(textFile) };

		textData * const tPtr{ new textData[wordCount] }; // Lock your heap pointers with const. If it changes, you're doomed. 

		fillClass(textFile, tPtr, wordCount);
		editClass(tPtr, wordCount);
		countWords(tPtr, wordCount);
		sortWords(tPtr, wordCount);
		printTopTen(tPtr);

		std::cout << std::endl;

		delete[] tPtr;
		// tPtr = nullptr; // Don't need to erase, it's exiting scope. 
	}

	return 0;
}
