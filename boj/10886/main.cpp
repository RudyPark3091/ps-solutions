#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n, x;
	int yes = 0, no = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x) yes++;
		else no++;
	}

	if (yes < no)
		cout << "Junhee is not cute!" << '\n';
	else
		cout << "Junhee is cute!" << '\n';

	return 0;
}
