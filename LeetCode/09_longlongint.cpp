# include<iostream>
using namespace std;

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    long long int reverse = 0;
    int num = x;
    for (int i = 0; num; i++) {
        reverse = reverse * 10 + num % 10;
        num /= 10;
        cout << "i = " << i << ":\treverse = " << reverse << endl;
    }
    if (reverse == x) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    cout << isPalindrome(1234567899) << endl << endl;
    cout << isPalindrome(1234554321) << endl << endl;
    cout << isPalindrome(-212) << endl << endl;
}