#include<iostream>
#include<vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int size1 = nums1.size();
    int size2 = nums2.size();
    if (size1 > size2) {
        return findMedianSortedArrays(nums2, nums1);
    }
    int index1, index2;
    int nums1Start, nums1End;
    int nums1min, nums2min, nums1max, nums2max;
    cout << "initialization: " << endl;
    nums1Start = 0;
    nums1End = size1;
    cout << "\tnums1Start = " << nums1Start << "\tnums1End = " << nums1End << endl;
    //(4,5):            3 = 10/2 -2
    //  sta min max*    end       
    //  0   1   2   3
    //          min max*
    //  0   1   2   3   4
    //(3,5):            3 = 9/2 -1
    //  min max*    end
    //  0   1   2
    //          min max*
    //  0   1   2   3   4
    //(4,4):            2 = 9/2 -2
    //  sta min max*    end
    //  0   1   2   3
    //      min max*
    //  0   1   2   3
    for (int i = 0; nums1Start <= nums1End; i++) {
        cout << "i = " << i << endl;
        index1 = nums1Start + (nums1End - nums1Start) / 2;
        index2 = (size1 + size2 + 1) / 2 - index1;
        nums1min = INT_MIN;
        nums2min = INT_MIN;
        nums1max = INT_MAX;
        nums2max = INT_MAX;
        if (index1 > 0) {
            nums1min = nums1[index1 - 1];
        }
        if (index2 > 0) {
            nums2min = nums2[index2 - 1];
        }
        if ((index1 >= 0) && (index1 < size1)) {
            nums1max = nums1[index1];
        }
        if ((index2 >= 0) && (index2 < size2)) {
            nums2max = nums2[index2];
        }
        cout << "\tnums1Start = " << nums1Start << "\tnums1End = " << nums1End << endl;
        cout << "\tindex1 = " << nums1Start << " + (" << nums1End << "-" << nums1Start << ") / 2 = " << index1 << "\tnums1[" << index1 - 1 << "] = " << nums1min << "\tnums1[" << index1 << "] = " << nums1max << endl;
        cout << "\tindex2 = (" << size1 << "+" << size2 << "+1) / 2 - " << index1 << " = " << index2 << "\tnums2[" << index2 - 1 << "] = " << nums2min << "\tnums2[" << index2 << "] = " << nums2max << endl;
        if (nums1min <= nums2max && nums2min <= nums1max) {
            if ((size2 + size1) % 2 == 0) {
                return (max(nums1min, nums2min) + min(nums1max, nums2max)) / 2.0;
            }
            else {
                return max(nums1min, nums2min);
            }
        }
        else {
            if (nums1min > nums2max) {
                nums1End = index1 - 1;
            }
            else {
                nums1Start = index1 + 1;
            }
        }
    }
    return 0;
}

int main() {
    vector<int> nums1 = { 1,2,3,4 };
    vector<int> nums2 = { 5,6,7,8,9 };
    cout << findMedianSortedArrays(nums1, nums2) << endl << endl;

    vector<int> nums3 = { 1,2,3 };
    vector<int> nums4 = { 4,5,6,7,8 };
    cout << findMedianSortedArrays(nums3, nums4) << endl << endl;

    vector<int> nums5 = { 1,2,3,4 };
    vector<int> nums6 = { 4,5,6,7 };
    cout << findMedianSortedArrays(nums5, nums6) << endl << endl;
}