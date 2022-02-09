#include<iostream>
#include<vector>
using namespace std; 

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> output;
    for (int i = 0; i < nums.size() - 1; i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                output.push_back(i);
                output.push_back(j);
                return output;
            }
        }
    }
    output.push_back(NULL);
    return output;
}

int main() {
    vector<int> nums = {2,7,11,19};
    vector<int> index;
    index = twoSum(nums, 21);
    if (index.size() == 2) {
        cout << "sum = 21, the index of the two number is " << index[0] << " and " << index[1] << endl << endl;
    }
    else {
        cout << "sum = 21, not found" << endl << endl;
    }
    index = twoSum(nums, 31);
    if (index.size() == 2) {
        cout << "sum = 31, the index of the two number is " << index[0] << " and " << index[1] << endl << endl;
    }
    else {
        cout << "sum = 31, not found" << endl << endl;
    }
}