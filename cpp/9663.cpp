#include <iostream>
#include <cmath>

using namespace std;

const int MAX_SIZE 15

int board[MAX_SIZE];
int n;
int cnt;

void path(int y) {
    int ko;
    if (y == n) {
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++) {
        ko = 1;
        for (int j = 0; j < y; j++) {
            if (board[j] == i || abs(y - j) == abs(i - board[j])) {
                ko = 0;
                break;
            }
        }
        if (ko) {
            board[y] = i;
            path(y + 1);
        }
    }
}

int main() {
    cin >> n;
    cnt = 0;
    path(0);

    cout << cnt << '\n';

    return 0;
}