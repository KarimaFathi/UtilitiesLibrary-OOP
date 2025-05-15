#pragma once
#include<iostream>
#include<vector>
#include<cctype>
using namespace std;


class ClassString
{
private:
	string _value;
	static bool isVowel(char c1) {
		return ((c1 == 'a') || (c1 == 'e') || (c1 == 'i') || (c1 == 'o') || (c1 == 'u'));
	}
	static char changeCase(char c1) {
		return (isupper(c1) ? tolower(c1) : toupper(c1));

	}

public:
	ClassString() {
		_value = " ";
	}
	ClassString(string value) {
		_value = value;
	}


	string getString() {
		return _value;
	}
	void setString(string value) {
		_value = value;
	}
	__declspec(property(get = getString, put = setString))string value;

	static short Length(string S1)
	{
		return S1.length();
	};

	short Length()
	{
		return _value.length();
	};

	//Exo23
	static void printFirstLetterOfStringWords(string stringToManipulate) {
		bool isFirstLetter = true;
		for (short i = 0; i < stringToManipulate.length(); i++) {
			if (stringToManipulate[i] != ' ' && isFirstLetter) {
				cout << stringToManipulate[i] << endl;
			}
			isFirstLetter = (stringToManipulate[i] == ' ' ? true : false);
		}
	}

	void printFirstLetterOfStringWords() {
		return printFirstLetterOfStringWords(_value);
	}

	//Exo24
	static string capitalizeFirstLetter(string s) {
		bool isFirstLetter = true;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != ' ' && isFirstLetter) {
				s[i] = toupper(s[i]);
			}
			isFirstLetter = (s[i] == ' ' ? true : false);
		}
		return s;
	}

	string capitalizeFirstLetter() {
		return capitalizeFirstLetter(_value);
	}

	//Exo25
	static string toLowerCaseFirstLetter(string s) {
		bool isFirstLetter = true;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != ' ' && isFirstLetter) {
				s[i] = tolower(s[i]);
			}
			isFirstLetter = (s[i] == ' ' ? true : false);
		}
		return s;
	}

	string toLowerCaseFirstLetter() {
		return toLowerCaseFirstLetter(_value);
	}

	static string upperAllString(string S3)
	{
		for (int i = 0; i < S3.length(); i++)
		{
			S3[i] = toupper(S3[i]);
		}
		return S3;
	}

	//Exo26
	string upperAllString() {
		return upperAllString(_value);
	}

	static string lowerAllString(string S3)
	{
		for (int i = 0; i < S3.length(); i++)
		{
			S3[i] = tolower(S3[i]);
		}
		return S3;
	}

	string lowerAllString() {
		return  lowerAllString(_value);
	}

	//Exo28
	static string invertStringAllLettersCase(string s1) {
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] != ' ') {
				s1[i] = changeCase(s1[i]);
			}
		}
		return s1;
	}

	string invertStringAllLettersCase() {
		return invertStringAllLettersCase(_value);
	}

	//Exo29
	static short countUpperLetterCase(string s1) {
		short capitalCounter = 0;
		for (short i = 0; i < s1.length(); i++) {
			if (isupper(s1[i])) {
				capitalCounter++;
			}
			else continue;
		}
		return capitalCounter;
	}

	short countUpperLetterCase() {
		return countUpperLetterCase(_value);
	}

	static short countLowerLetterCase(string s1) {
		short lowerCounter = 0;
		for (short i = 0; i < s1.length(); i++) {
			if (islower(s1[i])) {
				lowerCounter++;
			}
			else continue;
		}
		return lowerCounter;
	}

	short countLowerLetterCase() {
		return countLowerLetterCase(_value);
	}


	//Exo31
	static short countCharInString(string s1, char c1, bool matchCase = true) {
		short charCounter = 0;
		for (short i = 0; i < s1.length(); i++) {
			if (matchCase == true) {
				if (s1[i] == c1) {
					charCounter++;
				}
			}
			else {
				if (tolower(s1[i]) == tolower(c1)) {
					charCounter++;
				}
			}
		}

		return charCounter;
	}

	short countCharInString(char c1, bool matchCase) {
		return countCharInString(_value, c1, matchCase);
	}

	//Exo33
	static short countVowelsInString(string s1) {
		short counter = 0;
		for (short i = 0; i < s1.length(); i++) {
			if (isVowel(tolower(s1[i]))) {
				counter++;
			}
		}
		return counter;
	}

	short  countVowelsInString() {
		return countVowelsInString(_value);
	}

	//Exo34
	static void findVowelsInString(string s1) {
		vector<char> charInString;
		for (short i = 0; i < s1.length(); i++) {
			if (isVowel(tolower(s1[i]))) {
				charInString.push_back(s1[i]);
			}
		}
		for (char& i : charInString) {
			cout << i << "\t";
		}
	}

	void findVowelsInString() {
		return findVowelsInString(_value);
	}

	//Exo35
	static void printWordByWord(string s1) {
		string delim = " ";
		short pos;
		string word;
		cout << "\nYour string words are : \n\n";
		while ((pos = s1.find(delim)) != std::string::npos) {
			word = s1.substr(0, pos);
			if (word != "") {
				cout << word << endl;
				s1.erase(0, pos + delim.length());
			}
		}
		if (s1 != "") {
			cout << s1 << endl;
		}
	}

	void printWordByWord() {
		printWordByWord(_value);
	}

	//Exo36
	static short countWordsInString(string s1) {
		string delim = " ";
		short pos;
		string word;
		short counter = 0;
		while ((pos = s1.find(delim)) != std::string::npos) {
			word = s1.substr(0, pos);
			if (word != "") {
				counter++;
				s1.erase(0, pos + delim.length());
			}
		}
		if (s1 != "") {
			counter++;
		}
		return counter;
	}

	short countWordsInString() {
		return countWordsInString(_value);
	}

	//Exo37 to be back 
	static vector<string> splitString(string s1, string delim) {
		short pos;
		vector<string> vString;
		string word;
		while ((pos = s1.find(delim)) != s1.npos) {
			word = s1.substr(0, pos);
			if (word != "") {
				vString.push_back(word);
				s1.erase(0, pos + delim.length());
			}
		}
		if (s1 != "") {
			vString.push_back(s1);
		}
		return vString;
	}
	vector<string> splitString(string Delim)
	{
		return splitString(_value, Delim);
	}


	//Exo38
	static string trimLeft(string s1) {
		for (short i = 0; i < s1.length(); i++) {
			if (s1[i] != ' ') {
				return s1.substr(i, s1.length() - i);
			}
		}
		return s1;
	}

	string trimLeft() {
		return trimLeft(_value);
	}

	static string trimRight(string s1) {
		for (short i = s1.length(); i > 0; i--) {
			if (s1[i] != ' ') {
				return s1.substr(0, i + 1);
			}
		}
		return s1;
	}

	string trimRight() {
		return trimRight(_value);
	}

	string trim() {
		return trimRight(trimLeft(_value));
	}

	//Exo39
	static string joinString(vector<string> vString, string delim) {
		string resultedString = "";
		for (string& str : vString) {
			str = str + delim;
			resultedString += str;
		}
		return resultedString.substr(0, (resultedString.length() - delim.length()));
	}

	//Exo40 "Overloading"
	string joinString(string arr[100], short length, string delim) {
		string resultedString = "";
		for (short i = 0; i < length; i++) {
			arr[i] = arr[i] + delim;
			resultedString += arr[i];
		}
		return resultedString.substr(0, (resultedString.length() - delim.length()));
	}

	//Exo41
	static string reverseWordInString(string s1) {
		string s2 = "";
		vector<string> vString = splitString(s1, " ");
		vector <string>::iterator iter = vString.end();
		while (iter != vString.begin()) {
			iter--;
			s2 += *iter + " ";
		}
		return s2;
	}

	string reverseWordInString() {
		return reverseWordInString(_value);
	}

	//Exo42
	static string replaceString(string s1, string wordToReplace, string newWord) {
		short pos = s1.find(wordToReplace);
		while (pos != std::string::npos) {
			s1 = s1.replace(pos, wordToReplace.length(), newWord);
			pos = s1.find(wordToReplace);
		}
		return s1;
	}

	string replaceString(string wordToReplace, string newWord) {
		return replaceString(_value, wordToReplace, newWord);
	}

	//Exo44
	static string removePunctuations(string s1) {
		for (int i = 0; i < s1.length(); i++) {
			if (ispunct(s1[i])) {
				s1.erase(i, 1);
				i--;
			}
		}
		return s1;
	}
	string removePunctuations() {
		return removePunctuations(_value);
	}
};
