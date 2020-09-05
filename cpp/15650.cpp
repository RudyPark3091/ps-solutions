#include <cstdio>
#include <vector>
using namespace std;

int n, m;
vector<int> a;

void solve(int index, int cnt) {
    if (cnt == m) {
        for (auto i : a) printf("%d ", i+1);
        printf("\n");
        return;
    }
    for (int i=index; i<n; i++) {
        a.push_back(i);
        solve(i+1, cnt+1);
        a.pop_back();
    }
}

int main() {
    scanf("%d %d", &n, &m);
    solve(0, 0);
    return 0;
}
