#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, ans;
    int rgb[1000][3];
    int marr[1000][3];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
    }

    marr[0][0] = rgb[0][0];
    marr[0][1] = rgb[0][1];
    marr[0][2] = rgb[0][2];

    for (int i = 1; i < n; i++) {
        marr[i][0] = min(marr[i-1][1], marr[i-1][2]) + rgb[i][0];
        marr[i][1] = min(marr[i-1][0], marr[i-1][2]) + rgb[i][1];
        marr[i][2] = min(marr[i-1][1], marr[i-1][0]) + rgb[i][2];
    }

    ans = min(marr[n-1][0], marr[n-1][1]);
    ans = min(ans, marr[n-1][2]);
    cout << ans << '\n';

    return 0;
}