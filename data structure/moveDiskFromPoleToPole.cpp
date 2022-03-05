#include<iostream>
#include<vector>
using namespace std;


/*
int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) {
        return 0; 
    }

    int rowSize = matrix.size(), collumnSize = matrix[0].size(), maxRectangle = 0;
    vector<vector<int>> collumn(rowSize, vector<int>(collumnSize,0)), row(rowSize, vector<int>(collumnSize,0));
    int rowCount, collumnCount;
    int minCollumn, currRectangle;
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < collumnSize; j++) {
            if (matrix[i][j] == '1') {
                if (j - 1 >= 0) {
                    row[i][j] = row[i][j - 1]+1;
                }
                else {
                    row[i][j] = 1;
                }
                if (i - 1 >= 0) {
                    collumn[i][j] = collumn[i - 1][j]+1;
                }
                else {
                    collumn[i][j] = 1;
                }
                minCollumn = collumn[i][j];
                cout << "(" << i << "," << j << ") " << endl;
                for (int k = 1; k < row[i][j]; k++) {
                    cout<<"\t"
                        minCollumn = min(minCollumn, collumn[i][j - k]);
                        currRectangle = minCollumn * k;
                        maxRectangle = max(currRectangle, maxRectangle);
                    
                }
            }
        }
    }
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < collumnSize; j++) {
            cout << collumn[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < collumnSize; j++) {
            cout << row[i][j] << "\t";
        }
        cout << endl;
    }
    return maxRectangle;
}

int main() {
    vector<vector<char>> matrix;
    matrix = { {'1','0','1','0','0'}, { '1', '0', '1', '1', '1' }, { '1', '1', '1', '1', '1' }, { '1', '0', '0', '1', '0' } };
    cout << maximalRectangle(matrix) << endl;
}*/

void move(int n, int start, int end) {
    int other;
    switch (start+end)    {
    case(3):other = 3; break;
    case(4):other = 2; break;
    case(5):other = 1; break;
    }
    if (n == 1) {
        cout << start << " -> " << end << endl;
    }
    else {
        move(n - 1, start, other);
        cout << start << " -> " << end << endl;
        move(n - 1, other, end);
    }
}

int main() {
    move(5, 1, 3);
}