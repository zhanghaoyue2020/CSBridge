#include<iostream>
#include<vector>
using namespace std;

//Time Limit Exceeded
int jump(vector<int>& nums) {
	if (nums.size() == 1) {
		return 0;
	}
	else {
		int maxJumpLength = nums[0];
		vector<int> newNums;
		int currJumpStep = 0;
		int ans = nums.size() - 1;
		for (int i = 1; i <= maxJumpLength && i < nums.size(); i++) {
			newNums.clear();
			for (int j = i; j < nums.size(); j++) {
				newNums.push_back(nums[j]);
			}
			currJumpStep = jump(newNums) + 1;
			ans = (currJumpStep < ans ? currJumpStep : ans);
		}
		return ans;
	}
}

int main() {
	vector<int> vector;
	vector = { 2,3,1,1,4 };
	cout << jump(vector) << endl;
}