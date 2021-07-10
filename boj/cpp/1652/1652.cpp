#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int n;
string s;
vector<string> arr;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		arr.push_back(s);
	}

	int h_cnt = 0;
	for (string ss : arr) {
		istringstream strm(ss);
		string buf;
		while (getline(strm, buf, 'X')) {
			if (buf.size() >= 2) h_cnt++;
		}
	}
	cout << h_cnt << ' ';

	int v_cnt = 0;
	for (int i = 0; i < n; i++) {
		string ss;
		for (int j = 0; j < n; j++) {
			ss += arr[j][i];
		}
		istringstream strm(ss);
		string buf;
		while (getline(strm, buf, 'X')) {
			if (buf.size() >= 2) v_cnt++;
		}
	}

	cout << v_cnt << '\n';
	return 0;
}
