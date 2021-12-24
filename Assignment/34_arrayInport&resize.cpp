#include<iostream>
#include<string>
using namespace std;

string* cutIntoWordsArray(string sentence, int& outWordsArrSize) {
	//frame;
	string* wordsArr;
	int wordsArrSize, wordsArrPhysicalSize;
	//inner variable;
	string currWords;
	int startInd, length;
	//initialization;
	wordsArr = new string[1];
	wordsArrSize = 0;
	wordsArrPhysicalSize = 1;
	startInd = 0;
	while (startInd < sentence.length()) {
		//if the array is fulled, resize it
		if (wordsArrSize == wordsArrPhysicalSize) {
			string* newWordsArr;
			newWordsArr = new string[2 * wordsArrPhysicalSize];
			for (int i = 0; i < wordsArrPhysicalSize; i++) {
				newWordsArr[i] = wordsArr[i];
			}
			delete[] wordsArr;
			wordsArr = newWordsArr;
			wordsArrPhysicalSize *= 2;
		}
		length = sentence.find(" ", startInd) - startInd;
		if (length < 0) {
			length = sentence.length() - startInd;
			currWords = sentence.substr(startInd, length);
			wordsArr[wordsArrSize] = currWords;
			wordsArrSize++;
			break;
		}
		if (length > 0) {
			currWords = sentence.substr(startInd, length);
			wordsArr[wordsArrSize] = currWords;
			wordsArrSize++;
			startInd += length + 1;
		}
		if (length == 0) {
			startInd++;
		}
	}
	outWordsArrSize = wordsArrSize;
	return wordsArr;
}

int main() {
	string sentence = "You can do it";
	int arrSize;
	string* wordsArr = cutIntoWordsArray(sentence, arrSize);
	for (int i = 0; i < arrSize; i++) {
		cout << i + 1 << "  " << wordsArr[i] << endl;
	}
}