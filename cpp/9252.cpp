#include <iostream>
using namespace std;

int main() {
	string s1;
	string s2;
	string str = "";
	cin >> s1 >> s2;

	int arr[1001][1001] = { 0 };

	int n1 = s1.length();
	int n2 = s2.length();
	for (int i = 1; i <= n1; i++) {
		for (int j = 1; j <= n2; j++) {
			if (s1[i - 1] == s2[j - 1]) {
				arr[j][i] = arr[j - 1][i - 1] + 1;
			} else {
				arr[j][i] = max(arr[j - 1][i], arr[j][i - 1]);
			}
		}
	}

	int i = n1;
	int j = n2;
	while (arr[j][i] != 0) {
		if (arr[j - 1][i] == arr[j][i]) j -= 1;
		else if (arr[j][i - 1] == arr[j][i]) i -= 1;
		else {
			str = s1[i - 1] + str;
			i -= 1;
			j -= 1;
		}
	}

	int ans = arr[n2][n1];
	cout << ans << '\n';
	if (ans != 0) cout << str << '\n';
	return 0;
}
