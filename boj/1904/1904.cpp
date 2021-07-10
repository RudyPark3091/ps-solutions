#include <cstdio>
using namespace std;

int arr[1000001] = {0, 1, 2, };

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 3; i <= n; i++) { arr[i] = (arr[i-1] + arr[i-2]) % 15746; }
    printf("%d\n", arr[n]);
    return 0;
}