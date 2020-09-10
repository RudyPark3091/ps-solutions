#include <iostream>
using namespace std;
#define DIVIDER 10007
#define MAX 1001

int n, k;
int arr[MAX][MAX] = { 0 };

int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == j || j == 0) {
                arr[i][j] = 1;
            } else {
                arr[i][j] = (arr[i-1][j-1] + arr[i-1][j]) % DIVIDER;
            }
        }
    }

    cout << arr[n][k] << '\n';

    return 0;
}