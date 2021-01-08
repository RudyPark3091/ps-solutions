## Problem

[acmicpc.net/problem/14501]

## Example

input ->  
7  
3 10  
5 20  
1 10  
1 20  
2 15  
4 40  
2 200

output ->  
45

input ->  
10  
1 1  
1 2  
1 3  
1 4  
1 5  
1 6  
1 7  
1 8  
1 9  
1 10

ouput ->  
55

input ->  
10  
5 10  
5 9  
5 8  
5 7  
5 6  
5 10  
5 9  
5 8  
5 7  
5 6

output ->  
20

input ->  
10  
5 50  
4 40  
3 30  
2 20  
1 10  
1 10  
2 20  
3 30  
4 40  
5 50

output ->  
90

## Logic

이 문제는 딱 생겨먹은게 dp문제처럼 보인다.  
i번째 날의 상담을 한다/ 하지 않는다를 나눠 생각한다.  
i번째 날 까지 벌 수 있는 돈의 최댓값을 dp[i]라고 한다.  
i번째 날 일을 하면 해당하는 일을 모두 처리하는 동안 돈을 받지 못한다.  
따라서 `i + (걸리는 시간)`의 인덱스를 갱신해줘야 한다.  
이때 최댓값을 저장해야 하므로, 원래 존재하던 값과 갱신되는 값을 비교한다.  
이를 점화식으로 표현하면 `dp[i + time[i]] = max(dp[i + time[i]], dp[i] + money[i])`가 된다.  
i번째 날 일을 하지 않으면 단순히 오늘까지 벌 수 있는 돈이 내일로 넘어가게 된다.  
역시 dp배열에는 최댓값을 저장해야 하므로 갱신 시에 원래 값과 비교한다.  
이를 점화식으로 표현하면 `dp[i + 1] = max(dp[i + 1], dp[i])`가 된다.  
이를 `0 ~ N`으로 iteration 하며 반복하면 dp[n]값이 원하는 결과값이 된다.

## Source Code

```cpp
#include <iostream>
using namespace std;

int n;
int t[16], p[16];
int dp[16];

void input() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> t[i] >> p[i];
}

int solve() {
	int result = 0;
	for (int i = 0; i < n; i++) {
		if (i + t[i] <= n) {
			dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
		}
		dp[i + 1] = max(dp[i + 1], dp[i]);
	}
	return dp[n];
}

int main() {
	input();
	cout << solve() << '\n';
	return 0;
}
```

[acmicpc.net/problem/14501]: https://acmicpc.net/problem/14501
