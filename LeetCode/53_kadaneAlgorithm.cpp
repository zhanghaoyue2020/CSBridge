#include<iostream>
#include<vector>
using namespace std;

// same with dp,only no usage of array
int maxSubArray(vector<int>& nums) {
    int size = nums.size();
    int currMax;
    int ans;

    currMax = nums[0];
    ans = currMax;
    for (int i = 1; i < nums.size(); i++) {
        currMax = currMax > 0 ? currMax + nums[i] : nums[i];
        ans = max(ans, currMax);
    }
    return ans;
}

int main() {
    vector<int> nums;
    nums = { 1 };
    cout << maxSubArray(nums) << endl;
}