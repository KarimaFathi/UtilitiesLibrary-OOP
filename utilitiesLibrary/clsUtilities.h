#pragma once
#include <iostream>
#include <cstdlib>
#include "clsDate.h"
using namespace std;

class clsUtilities
{

public:
    enum enCharType { smallLetter = 1, capitalLetter = 2, specialCharacter = 4, digit = 3, mixChars = 5 };
    static void sRand() {
        srand((unsigned)time(NULL));
    }
    static int random(int from, int to) {
        int randNum = rand() % (to - from + 1) + from;
        return randNum;
    }

    static char getRandomChar(enCharType randomList) {
        if (randomList == mixChars) {
            randomList = (enCharType)random(1, 3);
        }
        switch (randomList) {
        case (smallLetter):
            return char(random(97, 122));
            break;
        case (capitalLetter):
            return char(random(65, 90));
            break;
        case (specialCharacter):
            return char(random(32, 47));
            break;
        case (digit):
            return char(random(48, 57));
            break;
        }
    }

    static  string generateWord(enCharType CharType, short Length)

    {
        string Word;

        for (int i = 1; i <= Length; i++)

        {

            Word = Word + getRandomChar(CharType);

        }
        return Word;
    }

    static string generateKey(enCharType charType = mixChars) {
        string Key = "";
        Key = generateWord(enCharType::mixChars, 4) + "-";
        Key = Key + generateWord(enCharType::mixChars, 4) + "-";
        Key = Key + generateWord(enCharType::mixChars, 4) + "-";
        Key = Key + generateWord(enCharType::mixChars, 4);
        return Key;
    }


    static void generateKeys(int numberOfKeys, enCharType charType) {
        string arrayKeys[100];
        for (int i = 0; i < numberOfKeys; i++) {
            arrayKeys[i] = generateKey();
            cout << "Key[" << i << "] : " << arrayKeys[i] << endl;
        }
    }

    static void  swap(int &A, int &B)
    {
        int temp;
        temp = A;
        A = B;
        B = temp;
    }

    static void  swap(char& A, char& B)
    {
        char temp;
        temp = A;
        A = B;
        B = temp;
    }

    static void  swap(bool& A, bool& B)
    {
        bool temp;
        temp = A;
        A = B;
        B = temp;
    }

    static void  swap(float& A, float& B)
    {
        float temp;
        temp = A;
        A = B;
        B = temp;
    }

    static void  swap(double& A, double& B)
    {
        double temp;
        temp = A;
        A = B;
        B = temp;
    }

    static void  swap(string& A, string& B)
    {
        string temp;
        temp = A;
        A = B;
        B = temp;
    }

    static void  swap(clsDate& Date1, clsDate& Date2)
    {
        clsDate TempDate;
        TempDate = Date1;
        Date1 = Date2;
        Date2 = TempDate;
    }

    static void shuffleArray(int arr[], int arrLength) {
        //srand(time(0));  // Seed the random generator once
        for (int i = arrLength - 1; i > 0; i--) {
            int j = rand() % (i + 1); // random index from 0 to i
            std::swap(arr[i], arr[j]);
        }
    }

    static void shuffleArray(string arr[], int arrLength) {
        //srand(time(0));  // Seed the random generator once
        for (int i = arrLength - 1; i > 0; i--) {
            int j = rand() % (i + 1); // random index from 0 to i
            std::swap(arr[i], arr[j]);
        }
    }

    static void fillArrayWithRandomNumbers(int array[], int arrLength,int min, int max) {
        for (int i = 0; i < arrLength; i++) {
            array[i] = random(min, max);
        }
    }


    static void fillArrayWithRandomWords(string array[], int arrLength, enCharType charType , int wordLength) {
        for (int i = 0; i < arrLength; i++) {
            array[i] = generateWord(charType, wordLength);
        }
    }

    static string  Tabs(short NumberOfTabs)
    {
        string t = "";

        for (int i = 1; i < NumberOfTabs; i++)
        {
            t = t + "\t";
            cout << t;
        }
        return t;

    }

    static string encryptWord(string word) {
        string wordAfterEnc = "";
        for (int i = 0; i < word.length(); i++) {
            wordAfterEnc += char(int(word[i]) + 2);
        }
        return wordAfterEnc;
    }

    static string decryptWord(string word) {
        string wordAfterDec = "";
        for (int i = 0; i < word.length(); i++) {
            wordAfterDec += char(int(word[i]) - 2);
        }
        return wordAfterDec;
    }

};

