#include <iostream>
#include <vector>
using namespace std;

const int NUM_MAX = 11;

long long res_max = -10000000001LL;
long long res_min = 10000000001LL;

int n;
long long t;

long long number_list[NUM_MAX];
bool visited[NUM_MAX];
int ops_list[4];
vector<int> ops_parsed;
long long arr[NUM_MAX];

int bar(int mode, int a, int b) {
    switch (mode) {
        case 0: return a + b;
        case 1: return a - b;
        case 2: return a * b;
        case 3:
            if (a < 0)
                return -(-a/b);
            else
                return a/b;
    }
}

void foo(int cnt) {
    if (cnt == n-1) {
        for (int i = 1; i < n; i++)
            number_list[0] = bar(arr[i-1], number_list[0], number_list[i]);
        
        if (res_max < number_list[0])
            res_max = number_list[0];
        if (res_min > number_list[0])
            res_min = number_list[0];
        number_list[0] = t;
        return;
    }

    for (int i = 0; i < n-1; i++) {
        if (!visited[i]) {
            visited[i] = true;
            arr[cnt] = ops_parsed[i];
            foo(cnt + 1);
            visited[i] = false;
        }
    }
}

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> number_list[i];
    t = number_list[0];
    for (int i = 0; i < 4; i++)
        cin >> ops_list[i];
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < ops_list[i]; j++)
            ops_parsed.push_back(i);
    }

    foo(0);
    cout << res_max << '\n' << res_min << endl;
}
