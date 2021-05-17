/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
#include <stack>
using namespace std;

int op_priority(char op) {
	if (op == '*' || op == '/') return 2;
	else if (op == '(') return 0;
	else return 1;
}

string solve(string str) {
	string ans = "";
	stack<char> s;
	char former_op;

	for (int i = 0; i < str.length(); i++) {
		char c = str[i];

		switch (c) {
			case '+':
			case '-':
			case '*':
			case '/':
				while (!s.empty() && (op_priority(c) <= op_priority(s.top()))) {
					cout << s.top();
					s.pop();
				}
				s.push(c);
				break;

			case '(':
				s.push(c);
				break;

			case ')':
				former_op = s.top();
				s.pop();

				while (former_op != '(') {
					cout << former_op;
					former_op = s.top();
					s.pop();
				}
				break;

			default:
				cout << c;
				break;
		}
	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}

	return ans;
}

int main() {
	string expr;
	cin >> expr;
	cout << solve(expr) << '\n';

	return 0;
}
