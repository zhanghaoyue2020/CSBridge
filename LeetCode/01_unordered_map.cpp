#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    cout << "generate unordered_map (key,value)" << endl;
    unordered_map<int, int> map;
    int size = nums.size();
    for (int i = 0; i < size; i++) {
        if (map.find(target - nums[i]) != map.end()) {
            cout << "i=" << i << " , find special Key " << target - nums[i] << endl;
            return { map[target - nums[i]],i };
        }
        else {
            cout << "i=" << i << " , push pair in unordered_map (" << nums[i] << "," << i << ")" << endl;
            map[nums[i]] = i;
        }
    }
    cout << "print unordered_map:" << endl;
    for (auto itemn = map.begin(); itemn != map.end(); itemn++) {
        cout << "(" << itemn->first << "," << itemn->second << ")" << endl;
    }
    return { size,size };
}

int main() {
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(19);
    vector<int> index;
    index = twoSum(nums, 21);
    cout << "sum = 21, the index of the two number is " << index[0] << " and " << index[1] << endl << endl;
    index = twoSum(nums, 31);
    cout << "sum = 31, the index of the two number is " << index[0] << " and " << index[1] << endl << endl;
}