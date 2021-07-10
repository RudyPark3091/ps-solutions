#include <iostream>
#include <stack>
using namespace std;

stack<int> s;
string line;

void check(void) {
    cin >> line;
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == '(') { s.push(1); }
        else if (line[i] == ')' && !s.empty()) { s.pop(); }
        else { cout << "NO\n"; return; }
    }
    if (s.empty()) { cout << "YES\n"; }
    else { cout << "NO\n"; }
    while (!s.empty()) { s.pop(); }
}

int main(void) {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) { check(); }

    return 0;
}