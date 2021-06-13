#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> money) {
	int n = money.size();
	int dp1[1000001] = { 0 };
	int dp2[1000001] = { 0 };

	dp1[0] = money[0];
	dp1[1] = max(money[0], money[1]);
	dp2[1] = money[1];

	for (int i = 2; i < n; i++) {
		dp1[i] = max(dp1[i - 1], money[i] + dp1[i - 2]);
		dp2[i] = max(dp2[i - 1], money[i] + dp2[i - 2]);
	}
	return max(dp1[n - 2], dp2[n - 1]);
}

int main() {
	cout << solution({1, 2, 3, 1}) << '\n';
	return 0;
}
