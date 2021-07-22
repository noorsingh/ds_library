#include <iostream>
using namespace std;

// function used for i/o in sublime text
void input() {
#ifndef ONLINE_JUDGE
    freopen("C:/Users/noor/Documents/Sublime/input.txt", "r", stdin);
    freopen("C:/Users/noor/Documents/Sublime/output.txt", "w", stdout);
#endif
}


#define N 9

bool isSafe(int arr[N][N], int row, int col, int num) {
    for (int x = 0; x < 9; x++)     // checking match in column
        if (arr[row][x] == num)
            return false;

    for (int x = 0; x < 9; x++)     // checking match in row
        if (arr[x][col] == num)
            return false;

    int startRow = row - row % 3,
        startCol = col - col % 3;

    for (int i = 0; i < 3; i++)     // checking match in block
        for (int j = 0; j < 3; j++)
            if (arr[i + startRow][j + startCol] == num)
                return false;

    return true;
}

bool solveSuduko(int arr[N][N], int row, int col) {
    if (row == N - 1 && col == N)
        return true;

    if (col == N) {
        row++;
        col = 0;
    }

    if (arr[row][col])
        return solveSuduko(arr, row, col + 1);

    for (int num = 1; num <= N; num++) {
        if (isSafe(arr, row, col, num)) {
            arr[row][col] = num;

            if (solveSuduko(arr, row, col + 1))
                return true;
        }

        arr[row][col] = 0;
    }

    return false;
}


int main() {
    input();

    int arr[N][N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];

    if (solveSuduko(arr, 0, 0)) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }
    }
    else
        cout << "no solution exists " << endl;

    return 0;
}

/*
3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0
*/