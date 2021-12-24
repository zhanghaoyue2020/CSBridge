#include<string>
#include<vector>
#include<iostream>
using namespace std;

string readText();
vector<string> cutIntoWords(string sentense);
int* countChar(string sentense);

int main() {
	string sentense;
	vector<string> words;
	sentense = readText();
	words = cutIntoWords(sentense);
	cout << words.size() << "\twords" << endl;
	int* count = NULL;
	count = countChar(sentense);
	for (int i = 0; i < 26; i++) {
		if (count[i] != 0) {
			cout << count[i] << "\t" << (char)('a' + i) << endl;
		}
	}
}

string readText() {
	string sentense;
	cout << "Please enter a line of text" << endl;
	getline(cin, sentense);
	return sentense;
}

vector<string> cutIntoWords(string sentense) {
	string currTerm;
	int startInd = 0;
	int length =0;
	vector<string> wordsVector;
	while (startInd< sentense.length()) {
		length=sentense.find(" ",startInd)-startInd;
		if (length < 0) {
			length = sentense.length() - startInd;
			currTerm = sentense.substr(startInd, length);
			wordsVector.push_back(currTerm);
			break;
		}
		if (length == 0) {
			startInd++;
		}
		if (length > 0) {
			currTerm = sentense.substr(startInd, length);
			wordsVector.push_back(currTerm);
			startInd += (length+1);
		}			
	}
	return wordsVector;
}

int *countChar(string sentense) {
	int *count = new int[26];
	for (int i = 0; i < 26; i++) {
		count[i] = 0;
	}
	//count the number;
	for (int i = 0; i < sentense.length(); i++) {
		if ((sentense[i] - 'A' < 26) && (sentense[i] - 'A' >= 0)) {
			count[sentense[i] - 'A']++;
		}
		else if ((sentense[i] - 'a' < 26) && (sentense[i] - 'a' >= 0)) {
			count[sentense[i] - 'a']++;
		}
	}
	return count;
}