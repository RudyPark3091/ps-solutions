#include <iostream>
#define DIVIDOR 1000000000
using namespace std;

int n;
long long arr[101][10] = {{0},{0,1,1,1,1,1,1,1,1,1},};

int main() {
    long long sum = 0;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) { arr[i][j] = arr[i-1][j+1]; }
            else if (j == 9) { arr[i][j] = arr[i-1][j-1]; }
            else { arr[i][j] = (arr[i-1][j-1] + arr[i-1][j+1]) % DIVIDOR; }
        }
    }

    for (int i = 0; i < 10; i++) {
        sum += arr[n][i];
    }

    cout << sum % DIVIDOR << '\n';
    return 0;
}