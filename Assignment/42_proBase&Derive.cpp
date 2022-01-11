#include<iostream>
#include<cstdlib>
#include<ctime>
#include<array>
#include<span>
using namespace std;

const int ROW = 20;
const int COLUMN = 20;
const int ANTS_INITIAL = 100;
const int BUGS_INITIAL = 5;
const int AVAILABLE = 0;
const int ANT = 1;
const int BUG = 2;

void printMap(int cells[][COLUMN]) {
	for (int j = 0; j < ROW; j++) {
		for (int k = 0; k < COLUMN; k++) {
			switch (cells[j][k]) {
			case(BUG):
				cout << "@"; break;
			case(ANT):
				cout << "*"; break;
			case(AVAILABLE):
				cout << " "; break;
			}
		}
		cout << endl;
	}
}

class Organism {
protected:
	int row;
	int column;
	int survive;
	int starve;
public:
	Organism(int row = 0, int column = 0, int survive = 0, int starve = 0) :
		row(row), column(column), survive(survive), starve(starve) {}
	virtual void move() {}
	virtual void breed() {}
	virtual void death() {}
	//accessors and mutators;
	void setRow(int row) { this->row = row; }
	void setColumn(int column) { this->column = column; }
	void setSurvive(int survive) { this->survive = survive; }
	void setStarve(int starve) { this->starve = starve; }
	int getRow() { return row; }
	int getColumn() { return column; }
	int getSurvive() { return survive; }
	int getStarve() { return starve; }
	//op
	void LEFT() { column--; }
	void RIGHT() { column++; }
	void UP() { row--; }
	void DOWN() { row++; }
	//func
	bool searchNearby(int SEARCH, int arr[][COLUMN], int outDirectionArr[], int& outDirection);
	bool moveToAvailiableCell(int CRITTER, int arr[][COLUMN]);
	template<class T>
	void deleteCritter(T critterArr[], int& critterArrSize);
	template<class T>
	bool createNewCritter(T crittersArr[], int& crittersArrSize, int CRITTER, int arr[][COLUMN]);
	void updateMap(int origin, int now, int op, int arr[][COLUMN]);
};

class Ant : public Organism {
public:
	Ant(int row = 0, int column = 0, int survive = 0, int starve = 0) :
		Organism(row, column, survive, starve) {};
	void move(int arr[][COLUMN]) {
		moveToAvailiableCell(ANT, arr);
		survive++;
		return;
	}
	void breed(int arr[][COLUMN], Ant antsArr[], int& antsArrSize) {
		if (survive >= 3) {
			if (createNewCritter(antsArr, antsArrSize, ANT, arr) == true) {
				survive = 0;
				return;
			}
		}
	}
	void death(int arr[][COLUMN]) {
		return;
	}
};

class Bug : public Organism {
public:
	Bug(int row = 0, int column = 0, int survive = 0, int starve = 0) :
		Organism(row, column, survive, starve) {};
	void move(int arr[][COLUMN], Ant antsArr[], int& antsArrSize) {
		if (eatAnt(antsArr, antsArrSize, arr) == true) {
			survive++;
			starve = 0;
			return;
		}
		else {
			moveToAvailiableCell(BUG, arr);
			survive++;
			starve++;
			return;
		}
	}
	void breed(int arr[][COLUMN], Bug bugsArr[], int& bugsArrSize) {
		if (survive >= 8) {
			if (createNewCritter(bugsArr, bugsArrSize, BUG, arr) == true) {
				survive = 0;
				return;
			}
		}
	}
	void death(int arr[][COLUMN], Bug bugsArr[], int& bugArrSize) {
		if (starve >= 3) {
			//updateMap;
			arr[row][column] = AVAILABLE;
			deleteCritter(bugsArr, bugArrSize);
			return;
		}
	}
	//func
	bool eatAnt(Ant antsArr[], int& antsArrSize, int arr[][COLUMN]);
};


//true: there is an SEARCH at LIFT RIGHT UP DOWN;
//false: there is not any SEARCH;
bool Organism::searchNearby(int SEARCH, int arr[][COLUMN], int outDirectionArr[], int& outDirection) {
	//initialize direction array;
	for (int i = 0; i < 4; i++) {
		outDirectionArr[i] = -1;
	}
	outDirection = -1;
	int count = 0;
	//collect direction;
	if ((column - 1 >= 0) && (arr[row][column - 1] == SEARCH)) {
		outDirectionArr[0] = count;
		count++;
	}
	if ((column + 1 < COLUMN) && (arr[row][column + 1] == SEARCH)) {
		outDirectionArr[1] = count;
		count++;
	}
	if ((row - 1 >= 0) && (arr[row - 1][column] == SEARCH)) {
		outDirectionArr[2] = count;
		count++;
	}
	if ((row + 1 < ROW) && (arr[row + 1][column] == SEARCH)) {
		outDirectionArr[3] = count;
		count++;
	}
	//choose direction;
	switch (count) {
	case(0):
		return false;
	case(1):
	case(2):
	case(3):
	case(4):
		outDirection = rand() % count;
		return true;
	}
}

//true: there is an ant at LIFT RIGHT UP DOWN, move there,ant die;
//false: there is not any ant, don't move;
bool Bug::eatAnt(Ant antsArr[], int& antsArrSize, int arr[][COLUMN]) {
	//initialize;
	int directionArr[4] = {-1,-1,-1,-1};
	int direction = -1;
	Ant deadAnt = Ant(row, column, 0, 0);
	//eat;
	if (searchNearby(ANT, arr, directionArr, direction) == false) {
		return false;
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (directionArr[i] == direction) {
				updateMap(BUG, AVAILABLE, i, arr);
				switch (i) {
				case(0):
					LEFT();
					deadAnt.LEFT();	break;
				case(1):
					RIGHT();
					deadAnt.RIGHT(); break;
				case(2):
					UP();
					deadAnt.UP(); break;
				case(3):
					DOWN();
					deadAnt.DOWN();	break;
				}
				deadAnt.deleteCritter(antsArr, antsArrSize);
				break;
			}
		}
		return true;
	}
}

//true: there is an available cell at LIFT RIGHT UP DOWN, move there;
//false: there is not available cell, don't move; 
bool Organism::moveToAvailiableCell(int CRITTER, int arr[][COLUMN]) {
	//initialize;
	int directionArr[4] = { -1,-1,-1,-1 };
	int direction = -1;
	//move;
	if (searchNearby(AVAILABLE, arr, directionArr, direction) == false) {
		return false;
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (directionArr[i] == direction) {
				updateMap(CRITTER, AVAILABLE, i, arr);
				switch (i) {
				case(0):
					LEFT(); break;
				case(1):
					RIGHT(); break;
				case(2):
					UP(); break;
				case(3):
					DOWN(); break;
				}
				break;
			}
		}
		return true;
	}
}

//true: there is an available cell at LIFT RIGHT UP DOWN, create a new critter there;
//false: there is not available cell, don't create;
template<class T>
bool Organism::createNewCritter(T crittersArr[], int& crittersArrSize, int CRITTER, int arr[][COLUMN]) {
	//initialize;
	int directionArr[4] = {-1,-1,-1,-1};
	int direction = -1;
	T newCritter;
	//create;
	if (searchNearby(AVAILABLE, arr, directionArr, direction) == false) {
		return false;
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (directionArr[i] == direction) {
				newCritter = T(row, column, 0, 0);
				updateMap(CRITTER, CRITTER, i, arr);
				switch (i) {
				case(0):
					newCritter.LEFT(); break;
				case(1):
					newCritter.RIGHT(); break;
				case(2):
					newCritter.UP(); break;
				case(3):
					newCritter.DOWN(); break;
				}
				//generalizaCritter();
				crittersArr[crittersArrSize] = newCritter;
				crittersArrSize++;
				break;
			}
		}
		return true;
	}
}

//only delete critter from the CritterArr,not change the map;
template<class T>
void Organism::deleteCritter(T critterArr[], int& critterArrSize) {
	for (int i = 0; i < critterArrSize; i++) {
		if ((critterArr[i].getRow() == row) && (critterArr[i].getColumn() == column)) {
			for (int j = i; j < critterArrSize - 1; j++) {
				critterArr[j] = critterArr[j + 1];
			}
			critterArrSize--;
			return;
		}
	}
}

//only update critter on the map;
void Organism::updateMap(int origin, int now, int op, int arr[][COLUMN]) {
	switch (op) {
	case(0):
		arr[row][column] = now;
		arr[row][column - 1] = origin;
		break;
	case(1):
		arr[row][column] = now;
		arr[row][column + 1] = origin;
		break;
	case(2):
		arr[row][column] = now;
		arr[row - 1][column] = origin;
		break;
	case(3):
		arr[row][column] = now;
		arr[row + 1][column] = origin;
		break;
	}
}

int main() {
	//variables;
	int randomNum1, randomNum2, row, column;
	int cells[ROW][COLUMN];
	Bug bugArr[ROW * COLUMN];
	int bugArrSize = BUGS_INITIAL;
	Ant antArr[ROW * COLUMN];
	int antArrSize = ANTS_INITIAL;
	int days;
	//create seed of rand();
	srand(time(0));
	//I said there is a space;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COLUMN; j++) {
			cells[i][j] = AVAILABLE;
		}
	}
	//I said there are ants and bugs;
	for (int i = 0; i < BUGS_INITIAL;) {
		row = rand() % ROW;
		column = rand() % COLUMN;
		if (cells[row][column] == AVAILABLE) {
			cells[row][column] = BUG;
			bugArr[i] = Bug(row, column, 0, 0);
			i++;
		}
	}
	for (int i = 0; i < ANTS_INITIAL;) {
		row = rand() % ROW;
		column = rand() % COLUMN;
		if (cells[row][column] == AVAILABLE) {
			cells[row][column] = ANT;
			antArr[i] = Ant(row, column, 0, 0);
			i++;
		}
	}
	//print the cell;
	printMap(cells);
	cout << "please input the number of steps: " << endl;
	cin >> days;
	for (int i = 1;i<days; i++) {
		cout << i << "th:";
		for (int j = 0; j < antArrSize; j++) {
			antArr[j].move(cells);
			antArr[j].breed(cells, antArr, antArrSize);
		}
		for (int j = 0; j < bugArrSize; j++) {
			bugArr[j].move(cells,antArr,antArrSize);
			bugArr[j].breed(cells, bugArr, bugArrSize);
			bugArr[j].death(cells, bugArr, bugArrSize);
		}
		cout << "\tants = " << antArrSize;
		cout << "\tbugs = " << bugArrSize;
		cout << endl;
	}
}