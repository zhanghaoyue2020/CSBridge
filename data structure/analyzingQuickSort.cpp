#include<iostream>
using namespace std;

int* PARTITION(int* A, int p, int r){
	int x = A[p];
	static int pivot[2];
	pivot[0] = p;
	pivot[1] = p;
	int temp;
	for (int i = p + 1; i <= r; i++) {
		if (A[i] < x) {
			temp = A[i];
			A[i] = A[pivot[1]+1];
			A[pivot[1] + 1] = A[pivot[0]];
			A[pivot[0]] = temp;
			pivot[1]++;
			pivot[0]++;
			continue;
		}
		if (A[i] == x) {
			temp = A[i];
			A[i] = A[pivot[1] + 1];
			A[pivot[1] + 1] = temp;
			pivot[1]++;
			continue;
		}
	}
	return pivot;
}

void QUICKSORT(int* A, int p, int r) {
	if (p < r) {
		int* pivot = PARTITION(A, p, r);
		QUICKSORT(A, p, pivot[0] - 1);
		QUICKSORT(A, pivot[1] + 1, r);
	}
}

int main() {
	int A[9] = { 8,2,8,2,8,8,8,2,2 };
	QUICKSORT(A, 0, 8);
	for (int i = 0; i < 9; i++) {
		cout << A[i] << " ";
	}
}