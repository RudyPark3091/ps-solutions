#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string s;
	vector<string> v;

	cin >> s;
	for (int i = 1; i <= (int) s.length(); i++) {
		v.push_back(s.substr(s.length() - i, i));
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < (int) v.size(); i++) {
		cout << v[i] << '\n';
	}
	return 0;
}
