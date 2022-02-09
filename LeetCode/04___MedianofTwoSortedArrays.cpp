#include<iostream>
#include<vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int curr;
	int size, i, j;
	size = nums1.size() + nums2.size();
	i = 0;
	j = 0;
	//even nums;
	if (size % 2 == 0) {
		for (;;) {
			//nums1 ends;
			if (i == nums1.size()) {
				//reached median;
				if (i + j == size / 2) {
					return (curr + nums2[j]) / 2.0;
				}
				//not reached median;
				else {
					j = size / 2 - i - 1;
					return (nums2[j] + nums2[j + 1]) / 2.0;
				}
			}
			//nums2 ends;
			if (j == nums2.size()) {
				//reached median;
				if (i + j == size / 2) {
					return (curr + nums1[i]) / 2.0;
				}
				//not reached median;
				else {
					i = size / 2 - j - 1;
					return (nums1[i] + nums1[i + 1]) / 2.0;
				}
			}
			//reaches median;
			if (i + j == size / 2) {
				if (nums1[i] < nums2[j]) {
					return (curr + nums1[i]) / 2.0;
				}
				else {
					return (curr + nums2[j]) / 2.0;
				}
			}
			//continue search;
			else {
				if (nums1[i] < nums2[j]) {
					curr = nums1[i];
					i++;
				}
				else {
					curr = nums2[j];
					j++;
				}
			}
		}
	}
	//odd nums;
	else {
		for (;;) {
			//nums1 ends;
			if (i == nums1.size()) {
				//reached median;
				if (i + j == size / 2 + 1) {
					return (double)curr;
				}
				//not reached median;
				else {
					j = size / 2 + 1 - i;
					return (double)nums2[j - 1];
				}
			}
			//nums2 ends;
			if (j == nums2.size()) {
				//reached median;
				if (i + j == size / 2 + 1) {
					return (double)curr;
				}
				//not reached median;
				else {
					i = size / 2 + 1 - j;
					return (double)nums1[i - 1];
				}
			}
			//reaches median;
			if (i + j == size / 2 + 1) {
				return (double)curr;
			}
			//continue search;
			else {
				if (nums1[i] < nums2[j]) {
					curr = nums1[i];
					i++;
				}
				else {
					curr = nums2[j];
					j++;
				}
			}
		}
	}
}

int main() {
	vector<int> nums1 = { };
	vector<int> nums2 = { 2,3 };
	double median = findMedianSortedArrays(nums1, nums2);
	cout << median << endl;
}