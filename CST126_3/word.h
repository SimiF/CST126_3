#include <string>
// #include <iostream> // Unused

#ifndef __WORD_H__ // Name of header is the most common way to do this.
#define __WORD_H__

class textData
{
public:
	// textData(): wordOccurence{ 0 }{} ; // Not creating a constructor that is generated anyway. If you needed to make one, try to use a "member initializer list" when reasonable to do so. 
	void wordUpdate(const std::string w) { word = w; };
	std::string getWord() const { return word; }; // getters should most likely be marked const. 
	void charUpdate(const int i, const char c) { word[i] = c; };
	char getWordC(const int i) const { return word[i]; }; // getters should most likely be marked const. 
	int updateWC(const int i) { return wordOccurence = i; };
	void upWC() { wordOccurence++; };
	int getWC() const { return wordOccurence; }; // getters should most likely be marked const. 
	void update(const std::string s, const int i) { word = s; wordOccurence = i; };

private:
	std::string word;
	int wordOccurence{0};
};

#endif // __WORD_H__
