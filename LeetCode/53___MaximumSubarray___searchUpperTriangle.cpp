#include<iostream>
#include<vector>
using namespace std;

//  Time Limit Exceeded
int maxSubArray(vector<int>& nums) {
    int size = nums.size();
    int sum;
    int maxSum = INT_MIN;
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            sum = 0;
            for (int k = i; k <= j; k++) {
                sum += nums[k];
            }
            maxSum = (sum > maxSum ? sum : maxSum);
        }
    }
    return maxSum;
}
int main() {
    vector<int> nums;
    nums = { 5,4,-1,7,8 };
    cout << maxSubArray(nums) << endl;
}