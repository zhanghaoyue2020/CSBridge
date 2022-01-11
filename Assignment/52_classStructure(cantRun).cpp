#include<string>
#include<fstream>
#include<list>
using namespace std;

class Posts {
	string str;
	bool isAFile;
public:
	Posts(string newStr = "", bool newIsAFile = false): str(newStr), isAFile(newIsAFile) {}
	virtual int getSize() const=0;
	string getString() const{ return str; }
};

class TextContent : public Posts {
public:
	TextContent(string newStr = "") : Posts(newStr, false) {}
	int getSize() const {
		string text = getString();
		return text.size();
	}
};

class ImageContent : public Posts {
public:
	ImageContent(string newStr = "") : Posts(newStr, true) {}
	int getSize() const {
		string image = getString();
		ifstream inFile;
		while (!inFile.is_open()) {
			inFile.clear();
			inFile.open(image);
		}
		string templine;
		int size = 0;
		while (getline(inFile,templine)) {
			size += templine.size();
		}
		return size;
	}
};

class Site {
	list <Posts>* site;
public:
	Site(): site(nullptr) {}
	~Site() { site->clear(); }
};