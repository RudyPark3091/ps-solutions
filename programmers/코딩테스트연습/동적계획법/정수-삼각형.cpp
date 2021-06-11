#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> triangle) {
	int dp[501][501] = { 0 };
	dp[0][0] = triangle[0][0];
	int n = triangle.size();

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j] + triangle[i][j]);
			dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j] + triangle[i][j + 1]);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[n - 1][i]);
	}
	return ans;
}

int main() {
	cout << solution(
			{{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}}
			) << endl;
}
