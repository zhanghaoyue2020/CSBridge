#include<iostream>
#include<vector>
using namespace std;

//Time Limit Exceeded
bool canJump(vector<int>& nums) {
	if (nums.size() == 1) {
		return true;
	}
	else {
		int maxJumpLength = nums[0];
		vector<int> newNums;
		bool ans = false;
		if (maxJumpLength >= nums.size() - 1) {
			return true;
		}
		for (int i = 1; i <= maxJumpLength; i++) {
			newNums.clear();
			for (int j = i; j < nums.size(); j++) {
				newNums.push_back(nums[j]);
			}
			ans = (canJump(newNums) > ans ? true : ans);
		}
		return ans;
	}
}

int main() {
	vector<int> nums;
	nums = { 2,5,0,0 };
	cout << canJump(nums) << endl;
}