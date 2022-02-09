#include<iostream>
#include<vector>
using namespace std;

bool canJump(vector<int>& nums) {
    int size = nums.size();
    for (int i = size - 1; i >= 0; i--) {
        if (i + nums[i] >= size - 1)
            size = i + 1;
    }
    return size == 1;
}

int main() {
    vector<int> nums;
    nums = { 3,2,1,0,4 };
    cout << canJump(nums) << endl;
}