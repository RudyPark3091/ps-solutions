#include <iostream>
#include <vector>
#define square(i, j) ((i/3)*3 + j/3)
using namespace std;

int sudoku[9][9];
bool row[9][10];  // 0-9 -> LENGTH: 10
bool col[9][10];
bool sqr[9][10];

void solve(int cnt) {
    if (cnt == 81) {
        cout << '\n';
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) { cout << sudoku[i][j] << ' '; }
            cout << '\n';
        }
        exit(0);
    }

    int n = cnt / 9;  // ROW NUM
    int m = cnt % 9;  // COL NUM

    if (sudoku[n][m] == 0) {
        for (int i = 1; i < 10; i++) {
            if (!row[n][i] && !col[m][i] && !sqr[square(n, m)][i]) {
                row[n][i] = true;
                col[m][i] = true;
                sqr[square(n, m)][i] = true;

                sudoku[n][m] = i;
                solve(cnt + 1);
                sudoku[n][m] = 0;
                
                row[n][i] = false;
                col[m][i] = false;
                sqr[square(n, m)][i] = false;
            }
        }
    } else { solve(cnt + 1); }
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
            if (sudoku[i][j] != 0) {
                row[i][sudoku[i][j]] = true;
                col[j][sudoku[i][j]] = true;
                sqr[square(i, j)][sudoku[i][j]] = true;
            }
        }
    }

    solve(0);
    return 0;
}
