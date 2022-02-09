#include<iostream>
#include<vector>
using namespace std;

int trap(vector<int>& height) {
    int size = height.size();
    if (size == 0) {
        return 0;
    }
    vector<int> maxValueLeft(size);
    vector<int> maxValueRight(size);
    int ans;

    maxValueLeft[0] = height[0];
    maxValueRight[size - 1] = height[size - 1];
    ans = 0;

    // maxLeft
    for (int i = 1; i < size; i++) {
        maxValueLeft[i] = max(maxValueLeft[i - 1], height[i]);
    }
    for (vector<int>::iterator it = maxValueLeft.begin(); it != maxValueLeft.end(); it++) {
        cout << *it << "\t";
    }
    cout << endl;

    // maxRight
    for (int i = size - 2; i >= 0; i--) {
        maxValueRight[i] = max(maxValueRight[i + 1], height[i]);
    }
    for (vector<int>::iterator it = maxValueRight.begin(); it != maxValueRight.end(); it++) {
        cout << *it << "\t";
    }
    cout << endl;

    // calculate answer
    for (int i = 0; i < height.size(); i++) {
        ans += (min(maxValueLeft[i], maxValueRight[i]) - height[i]);
        cout << min(maxValueLeft[i], maxValueRight[i]) - height[i] << "\t";
    }
    cout << endl;
    return ans;
}

int main() {
    vector<int> height1 = { 2,0,4,3 };
    cout << trap(height1) << endl;
}