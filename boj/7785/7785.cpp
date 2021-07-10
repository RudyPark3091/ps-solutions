#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	map<string, bool> m;

	int n;
	string name, op;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> name >> op;
		if (op == "enter") {
			m.insert({name, true});
		} else {
			m.erase(name);
		}
	}

	for (auto i = m.rbegin(); i != m.rend(); i++) {
		cout << i -> first << '\n';
	}

	return 0;
}
