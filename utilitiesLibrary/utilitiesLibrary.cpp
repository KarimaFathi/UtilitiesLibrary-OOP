#include <iostream>
#include "clsUtilities.h"
using namespace std;

int main()
{
	
	clsUtilities::sRand();
	cout << clsUtilities::random(10,20) << endl;
	cout << clsUtilities::getRandomChar(clsUtilities::enCharType::mixChars) << endl;
	cout << clsUtilities::generateWord(clsUtilities::mixChars, 8) << endl;
	cout << clsUtilities::generateKey(clsUtilities::mixChars) << endl;
	clsUtilities::generateKeys(10, clsUtilities::mixChars);
	cout << endl;

	int a = 10, b = 20;
	cout << a << " " << b << endl;
	clsUtilities::swap(a, b);
	cout << a << " " << b << endl;

	clsDate d1(1, 10, 2020), d2(5, 5, 1990);
	d1.Print();
	cout << " ";
	d2.Print();
	swap(d1, d2);
	cout << endl;
	d1.Print();
	cout << " ";
	d2.Print();

	int arr[] = { 1,2,3,4,5 };
	clsUtilities::shuffleArray(arr, 5);
	cout << "\nArray after shuffle : \n";
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << endl;
	}

    string arr2[] = { "Ali","Ahmed","Naser","khalid","Hicham"};
	clsUtilities::shuffleArray(arr2, 5);
	cout << "\nArray after shuffle : \n";
	for (int i = 0; i < 5; i++) {
		cout << arr2[i] << endl;
	}

	int arr3[100];
	clsUtilities::fillArrayWithRandomNumbers(arr3, 5, 20, 50);
	cout << "\nArray after fill : \n";
	for (int i = 0; i < 5; i++) {
		cout << arr3[i] << endl;
	}

	string arr4[100];
	clsUtilities::fillArrayWithRandomWords(arr4, 5, clsUtilities::mixChars, 8);
	cout << "\nArray after fill : \n";
	for (int i = 0; i < 5; i++) {
		cout << arr4[i] << endl;
	}

	const short encryptionKey = 2;

    string text = "Leila";
	string textAfterEncryption,textAfterDecryption;

	textAfterEncryption = clsUtilities::encryptWord(text);
	textAfterDecryption = clsUtilities::decryptWord(textAfterEncryption);
	cout << "\nWord after encryption : " << textAfterEncryption << endl;
	cout << "\nWord after decryption : " << textAfterDecryption << endl;
}

