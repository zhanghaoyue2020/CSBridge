#include<iostream>
#include<vector>
using namespace std;

//1d dp
int jump(vector<int>& nums) {
	int size = nums.size();
	vector<int> dp(size, 0);
	int currSearchSize;
	int currJumpStep;
	int minJumpStep;

	dp[size - 1] = 0;
	for (int i = size - 2; i >= 0; i--) {
		currSearchSize = nums[i];
		minJumpStep = size;
		for (int j = 0; j < currSearchSize; j++) {
			if (i + j + 1 > size - 1) {
				break;
			}
			currJumpStep = dp[i + j + 1] + 1;
			minJumpStep = (currJumpStep < minJumpStep ? currJumpStep : minJumpStep);
		}
		dp[i] = minJumpStep;
	}
	return dp[0];
}

int main() {
	vector<int> vector;
	vector = { 2,1 };
	cout << jump(vector) << endl;
}