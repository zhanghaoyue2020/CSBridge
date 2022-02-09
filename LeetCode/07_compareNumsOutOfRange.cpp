# include<iostream>
using namespace std;

int reverse(int x) {
    int ans = 0;
    for (int i = 0; x; i++) {
        cout << "i = " << i;
        if (ans + (x % 10) / 10 > INT_MAX / 10 || ans + (x % 10) / 10 < INT_MIN / 10) {
            cout << "\tout of range" << endl;
            return 0;
        }
        ans = ans * 10 + x % 10;
        x /= 10;
        cout << "\tans = " << ans << endl;
    }
    return ans;
}

int main() {
    cout << reverse(1234567899) << endl << endl;
    cout << reverse(-321) << endl << endl;
    cout << reverse(-210) << endl << endl;
}