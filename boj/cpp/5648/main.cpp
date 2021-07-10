/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
string s;
vector<string> arr;
vector<long long> ans;

void setup() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;
		arr.push_back(s);
	}
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	setup();
	for (int i = 0; i < arr.size(); i++) {
		string buf = "";
		for (int j = 0; j < arr[i].length(); j++) {
			buf = arr[i][j] + buf;
		}
		ans.push_back(stoll(buf));
	}
	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}
