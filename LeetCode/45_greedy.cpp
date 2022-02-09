#include<iostream>
#include<vector>
using namespace std;

int jump(vector<int>& nums) {
    int maxReachableIndex;
    int currIndex;
    int ans = 0;
    //      2   3   1   1   4
    //      0   1   2   3   4
    //      i(maxReachable=2)   
    //          i(maxReachable=4)
    //              i(maxReachable=4)
    //                  i(maxReachable=4)
    maxReachableIndex = 0;
    currIndex = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        cout << "i = " << i;
        maxReachableIndex = max(maxReachableIndex, nums[i] + i);

        if (i == currIndex) {
            currIndex = maxReachableIndex;
            ans++;
        }
        cout << "\tmaxReachableIndex = " << maxReachableIndex << ", currIndex = " << currIndex << endl;
    }
    return ans;
}

int main() {
    vector<int> vector;
    vector = { 2,1 };
    cout << jump(vector) << endl << endl;
    vector = { 2,3,1,1,4 };
    cout << jump(vector) << endl << endl;
    vector = { 1,2,4,5,3, 3,2,8,4,4,3,1 };
    cout << jump(vector) << endl << endl;
}