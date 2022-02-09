#include<iostream>
#include<vector>
using namespace std;

//                          2           0           4           3
//  address                 From                                To
//  value       leftmax                                                     rightmax
// ans = 0   
//  address                             From                    To
//  value                   leftmax                                         rightmax
// +0
//  address                                         From        To
//  value                   leftmax                                         rightmax
// +(2-0)
//  address                                         From/To
//  value                   leftmax                             rightmax
// +0
//  address                                         To          From
//  value                                           leftmax     rightmax

int trap(vector<int>& height) {
    int size = height.size();
    int ans = 0;

    int heightFrom = 0;
    int heightTo = size - 1;
    int leftmax = -1;
    int rightmax = size;
    cout << "\t\t";
    for (vector<int>::iterator it = height.begin(); it != height.end(); it++) {
        cout << *it << "\t";
    }
    cout << endl;
    cout << "ini:\t";
    for (int i = -1; i < size + 1; i++) {
        if (i == heightFrom && i == heightTo) {
            cout << "From/To\t";
        }
        else if (i == heightFrom) {
            cout << "From\t";
        }
        else if (i == heightTo) {
            cout << "To\t";
        }
        else {
            cout << "\t";
        }
    }
    cout << endl;
    cout << "\t";
    for (int i = -1; i < size + 1; i++) {
        if (i == leftmax) {
            cout << "max\t";
        }
        else if (i == rightmax) {
            cout << "max\t";
        }
        else {
            cout << "\t";
        }
    }
    cout << endl;

    for (int i = 0; heightFrom <= heightTo; i++) {
        if (height[heightFrom] <= height[heightTo]) {
            if (leftmax == -1 || height[heightFrom] >= height[leftmax]) {
                leftmax = heightFrom;
            }
            else {
                ans = ans + height[leftmax] - height[heightFrom];
            }
            heightFrom++;
        }
        else {
            if (rightmax == size || height[heightTo] >= height[rightmax]) {
                rightmax = heightTo;
            }
            else {
                ans = ans + height[rightmax] - height[heightTo];
            }
            heightTo--;
        }
        cout << "i = " << i << "\t";
        for (int i = -1; i < size + 1; i++) {
            if (i == heightFrom && i == heightTo) {
                cout << "From/To\t";
            }
            else if (i == heightFrom) {
                cout << "From\t";
            }
            else if (i == heightTo) {
                cout << "To\t";
            }
            else {
                cout << "\t";
            }
        }
        cout << endl;
        cout << "\t";
        for (int i = -1; i < size + 1; i++) {
            if (i == leftmax) {
                cout << "max\t";
            }
            else if (i == rightmax) {
                cout << "max\t";
            }
            else {
                cout << "\t";
            }
        }
        cout << endl;
    }
    return ans;
}

int main() {
    vector<int> height1 = { 2,0,4,3 };
    cout << trap(height1) << endl;
}