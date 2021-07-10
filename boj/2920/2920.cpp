#include <iostream>
using namespace std;

int main() {
	int arr[8];
	bool asc = true;
	bool desc = true;

	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
		if (i > 0 && arr[i] != arr[i-1] + 1) asc = false;
		if (i > 0 && arr[i] != arr[i-1] - 1) desc = false;
	}

	if (asc) cout << "ascending" << '\n';
	else if (desc) cout << "descending" << '\n';
	else cout << "mixed" << '\n';

	return 0;
}
