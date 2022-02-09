#include<iostream>
#include<vector>
using namespace std;

//1D dp Time Limit Exceeded
bool canJump(vector<int>& nums) {
	int size = nums.size();
	vector<bool> dp(size, false);
	int currSearchSize;
	bool currCanJump;
	bool canJump;
	dp[size - 1] = true;
	for (int i = size - 2; i >= 0; i--) {
		currSearchSize = nums[i];
		canJump = false;
		for (int j = 0; j < currSearchSize; j++) {
			if (i + j + 1 > size - 1) {
				canJump = true;
				break;
			}
			currCanJump = dp[i + j + 1];
			canJump = (currCanJump > canJump ? currCanJump : canJump);
		}
		dp[i] = canJump;
	}
	return dp[0];
}

int main() {
	vector<int> nums;
	nums = { 3,2,1,0,4 };
	cout << canJump(nums) << endl;
}