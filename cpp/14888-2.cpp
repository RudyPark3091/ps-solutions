#include <stdio.h>

const int MAX_NUM = 11;

int arr[MAX_NUM], ops[4];
int n, minimum, maximum;

void foo(int cnt, int number) {
    if (cnt == n) {
        if (maximum < number) maximum = number;
        if (minimum > number) minimum = number;
        return;
    }

    if (ops[0]) { ops[0]--; foo(cnt + 1, number + arr[cnt]); ops[0]++; }
    if (ops[1]) { ops[1]--; foo(cnt + 1, number - arr[cnt]); ops[1]++; }
    if (ops[2]) { ops[2]--; foo(cnt + 1, number * arr[cnt]); ops[2]++; }
    if (ops[3]) { ops[3]--; foo(cnt + 1, number / arr[cnt]); ops[3]++; }
    return;
}

int main(void) {
	minimum = 1000000001, maximum = -1000000001;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    for (int i = 0; i < 4; i++) scanf("%d", &ops[i]);

    foo(1, arr[0]);
    printf("%d\n%d\n", maximum, minimum);
}