#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int trap(vector<int>& height) {
    int size = height.size();
    stack<int> st;
    int ans = 0;
    int highest1Index, highest2Index, iterval;

    //concentrate on highest1Index, only keep 3
    for (int i = 0; i < size; i++) {
        cout << "i = " << i;
        cout << "\t";
        for (stack<int> stForPrint = st; !stForPrint.empty(); stForPrint.pop()) {
            cout << "height[" << stForPrint.top() << "] = " << height[stForPrint.top()] << '\t';
        }
        cout << endl;
        for (int j = 0; !st.empty() && height[st.top()] < height[i]; j++) {
            cout << "\t\theight[" << st.top() << "] < height[" << i << "]";
            highest1Index = st.top();
            st.pop();
            if (st.empty()) {
                cout << "\tno updade" << endl;
                break;
            }
            highest2Index = st.top();
            iterval = i - 1 - highest2Index;
            ans += (min(height[highest2Index], height[i]) - height[highest1Index]) * iterval;
            cout << "\tans + (" << min(height[highest2Index], height[i]) << " - " << height[highest1Index] << ") * " << iterval << endl;
        }
        st.push(i);
    }
    return ans;
}

int main() {
    vector<int> height1 = { 2,0,8,3,0,9,5,1,6,8 };
    cout << trap(height1) << endl;
}