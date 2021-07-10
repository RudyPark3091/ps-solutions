#include <iostream>
#define MAX 1000001
using namespace std;

int n;
int arr[MAX];
int b, c;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> b >> c;

	long long sum = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > b) {
			sum += 1;
			arr[i] -= b;
			if (arr[i] % c == 0) {
				sum += arr[i] / c;
			} else {
				sum += arr[i] / c + 1;
			}
		} else {
			sum += 1;
			continue;
		}
	}
	cout << sum << '\n';
	return 0;
}
