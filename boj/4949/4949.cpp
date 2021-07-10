#include <iostream>
#include <stack>
using namespace std;

stack<int> s;
string line;

int c(int input) {
    if (input == ')') { return '('; }
    else if (input == ']') { return '['; }
    else { return '1'; }
}

int main() {
    while (true) {
        getline(cin, line);
        if (line == ".") {
            break;
            cout << "end\n";
        }

        for (int i = 0; i < line.length(); i++) {
            if (line[i] == '(' || line[i] == '[') { s.push(line[i]); }
            else if (line[i] == ')' || line[i] == ']') {
                if (s.empty() || s.top() != c(line[i])) { s.push('-'); break; }
                else { s.pop(); }
            }
        }

        if (s.empty()) { cout << "yes\n"; }
        else { cout << "no\n"; }
        
        while (!s.empty()) { s.pop(); }
    }
    return 0;
}