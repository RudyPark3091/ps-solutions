#include <iostream>
#include <vector>
using namespace std;

int mat[20][20];
vector<int> g1;
vector<int> g2;
bool visited[10];
int n, v1, v2;
int m = 20001;

void bar() {
    v1 = 0;
    v2 = 0;
    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < n/2; j++) {
            if (i != j) {
                v1 = v1 + mat[g1[i]-1][g1[j]-1];
                v2 = v2 + mat[g2[i]-1][g2[j]-1];
            }
        }
    }
    if (v1 > v2) {
        if (v1 - v2 < m) { m = v1 - v2; }
    } else {
        if (v2 - v1 < m) { m = v2 - v1; }
    }
}

void foo(int idx, int cnt) {
    if (cnt == n/2 && g1[0] == 1) {
        g2.clear();
        int j = 0;
        for (int i = 1; i <= n; i++) {
            if (g1[j % (n/2)] != i) { g2.push_back(i); }
            else { j++; }
        }

        bar();
        return;
    }

    for (int i = idx; i <= n; i++) {
        g1.push_back(i);
        foo(i+1, cnt+1);
        g1.pop_back();
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) { cin >> mat[i][j]; }
    }

    foo(0, 0);
    cout << m << '\n';

    return 0;
}