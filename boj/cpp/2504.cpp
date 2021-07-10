#include <iostream>
#include <stack>
using namespace std;

int main() {
	string str;
	stack<char> s;
	bool yes = true;
	int res = 0;
	int temp = 1;

	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (s.empty() && (str[i] == ')' || str[i] == ']')) {
			yes = false;
			break;
		}
		else if (str[i] == ')' && s.top() != '(') {
			yes = false;
			break;
		}
		else if (str[i] == ']' && s.top() != '[') {
			yes = false;
			break;
		}

		if (str[i] == '(') {
			temp *= 2;
			s.push('(');
		}
		else if (str[i] == ')' && s.top() == '(') {
			s.pop();
			if (str[i-1] == '(') res += temp;
			temp /= 2;
		}
		else if (str[i] == '[') {
			temp *= 3;
			s.push('[');
		}
		else if (str[i] == ']') {
			s.pop();
			if (str[i-1] == '[') res += temp;
			temp /= 3;
		}
	}

	if (yes && s.empty()) cout << res << '\n';
	else cout << 0 << '\n';
	return 0;
}
