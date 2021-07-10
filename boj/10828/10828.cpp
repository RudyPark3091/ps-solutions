#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> stack;

int main(void) {
    int n;
    string line;

    cin >> n;
    
    for (int i = 0; i <= n; i++) {
        getline(cin, line);
        
        string cmd = line.substr(0, 2);
        if (cmd == "pu") stack.push_back(stoi(line.substr(5)));
        else if (cmd == "po") {
            if (stack.empty()) cout << "-1\n";
            else {
                cout << stack.back() << '\n';
                stack.pop_back();
            }
        }
        else if (cmd == "si") cout << stack.size() << '\n';
        else if (cmd == "em") {
            if (stack.empty()) cout << "1\n";
            else cout << "0\n";
        }
        else if (cmd == "to") {
            if (stack.empty()) cout << "-1\n";
            else {
                cout << stack.back() << '\n';
            }
        }
    }

    return 0;
}