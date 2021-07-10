#include <iostream>
using namespace std;

int main() {
	int info[4][2];
	int man = 0;
	int res = 0;
	for (int i = 0; i < 4; i++) {
		cin >> info[i][0] >> info [i][1];
	}

	for (int i = 0; i < 4; i++) {
		man -= info[i][0];
		man += info[i][1];
		res = max(res, man);
	}

	cout << res << '\n';
	return 0;
}
