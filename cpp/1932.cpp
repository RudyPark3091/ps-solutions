#include <iostream>
using namespace std;

int n, ans;
int tri[501][10001] = {0};
int dp[501][10001] = {0};

int main() {
    cin >> n;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < i; j++) { cin >> tri[i][j]; }
    }

    dp[0][0] = tri[0][0];

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i][j] = max(dp[i][j], dp[i-1][j] + tri[i][j]);
            dp[i][j+1] = max(dp[i][j+1], dp[i-1][j] + tri[i][j+1]);
        }
    }

    ans = 0;
    for (int i = 0; i <= n; i++) {
        if (dp[n][i] > ans) { ans = dp[n][i]; }
    }

    cout << ans << '\n';

    return 0;
}