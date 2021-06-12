#include <iostream>
#include <vector>
#define DIV 1000000007
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
	int dp[101][101] = { 0 };
	dp[1][1] = 1;
	for (vector<int> coord : puddles) {
		dp[coord[0]][coord[1]] = -1;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == 1 && j == 1) continue;
			int a = dp[i - 1][j] == -1 ? 0 : dp[i - 1][j];
			int b = dp[i][j - 1] == -1 ? 0 : dp[i][j - 1];
			if (dp[i][j] != -1) dp[i][j] = (a + b) % DIV;
		}
	}

	int ans = dp[m][n];
	return ans;
}

int main() {
	cout << solution(4, 3, {{2, 2}}) << endl;
	return 0;
}
