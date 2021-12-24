#include<iostream>
using namespace std;

int jumpItWhithLowestCost(int arr[], int arrSize);

int main() {
	int arr[6] = { 0,3,80,6,57,10 };
	cout << jumpItWhithLowestCost(arr, 6) << endl;
}

int jumpItWhithLowestCost(int arr[], int arrSize) {
	int currCost, costOfMove, costOfJump;
	if (arrSize == 2) {
		//move
		currCost = 0;
		costOfMove = arr[arrSize - 1] + currCost;
		return costOfMove;
	}
	else if (arrSize == 3) {
		//move
		currCost = jumpItWhithLowestCost(arr, arrSize - 1);
		costOfMove = arr[arrSize - 1] + currCost;
		//jump
		currCost = 0;
		costOfJump = arr[arrSize - 1] + currCost;
		if (costOfMove < costOfJump) {
			return costOfMove;
		}
		else {
			return costOfJump;
		}
	}
	else {
		//move
		currCost = jumpItWhithLowestCost(arr, arrSize - 1);
		costOfMove = arr[arrSize - 1] + currCost;
		//jump
		currCost = jumpItWhithLowestCost(arr, arrSize - 2);
		costOfJump = arr[arrSize - 1] + currCost;
		if (costOfMove < costOfJump) {
			return costOfMove;
		}
		else {
			return costOfJump;
		}
	}
}