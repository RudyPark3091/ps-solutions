#include <iostream>
#include <sstream>
using namespace std;

int main() {
	string s, res = "";
	cin >> s;

	string buf;
	istringstream strm(s);
	while (getline(strm, buf, '-')) {
		res += buf[0];
	}

	cout << res << '\n';
	return 0;
}
