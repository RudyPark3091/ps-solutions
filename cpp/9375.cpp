#include <iostream>
#include <vector>
#define MAX 30
using namespace std;

int t, n, ans, count;
string name;

int main() {
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n;
        string ctgr[31];
        int cnt[31] = { 0 };

        for (int j = 0; j < n; j++) {
            count = 0;
            cin >> name;
            cin >> name;

            for (int k = 0; k <= count; k++) {
                if (ctgr[k] == name) { cnt[k]++; break; }
                ctgr[count++] == name;
                cnt[k] = 1;
            }
        }

        ans = 1;
        for (int j = 0; j < count; j++) { ans *= cnt[j]+1; }
        cout << ans-1 << endl;
    }
    return 0;
}