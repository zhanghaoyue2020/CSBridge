#include<iostream>
#include<vector>
using namespace std;

//1D dp
int maxSubArray(vector<int>& nums) {
    int size = nums.size();
    vector<int> dp(size);
    int ans;
    cout << "\t";
    for (int i = 0; i < size; i++) {
        cout << nums[i] << "\t";
    }
    cout << endl;
    dp[0] = nums[0];
    ans = dp[0];
    for (int i = 1; i < size; i++) {
        dp[i] = dp[i - 1] > 0 ? dp[i - 1] + nums[i] : nums[i];
        ans = max(ans, dp[i]);
    }
    cout << "\t";
    for (int i = 0; i < size; i++) {
        cout << dp[i] << "\t";
    }
    cout << endl;
    return ans;
}
int main() {
    vector<int> nums;
    nums = { 5,4,-1,7,8 };
    cout << maxSubArray(nums) << endl;
}