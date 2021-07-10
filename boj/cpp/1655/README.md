## Problem
[acmicpc.net/problem/1655]   
   
## Example
input ->   
7   
1  
5  
2  
10  
-99  
7  
5  
   
output ->  
1  
1  
2  
2  
2  
2  
5  
  
## Logic
이 문제는 최소/최대 힙을 이용한 중간값 찾기 알고리즘을 이용해 풀 수 있다.  
배열에서 중간값을 찾기 위해선 정렬을 해야 한다.  
하지만 문제와 같이 계속 배열의 원소가 추가되는 상황에선 정렬으로 인한 시간 소모가 크다.  
따라서 삽입/삭제가 정렬과 함께 이뤄지는 힙 자료구조를 이용한다.  
최대/ 최소 힙을 하나씩 선언한다.  
이때, 최대 힙은 최소 힙보다 같거나 하나 많은 원소를 가져야 하며,
최대 힙의 루트 노드값(최대 힙의 최대값)이 최소 힙의 루트 노드값(최소 힙의 최소값)보다 작아야 한다.  
이 규칙이 만족되면 최대/ 최소 힙을 합한 원소들 중 중간값을 구할 수 있다.  
C++에서 힙은 priority_queue STL을 사용하여 간단히 구현할 수 있다.  
  
## Source Code
``` cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n, t;
  priority_queue<int, vector<int>, greater<int>> minq;
  priority_queue<int> maxq;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> t;

    if (minq.size() == maxq.size()) {
      maxq.push(t);
    } else {
      minq.push(t);
    }

    if (!maxq.empty() && !minq.empty()) {
      if (maxq.top() > minq.top()) {
        // swap
        int maxtp = maxq.top();
        int mintp = minq.top();

        maxq.pop(); minq.pop();
        maxq.push(mintp);
        minq.push(maxtp);
      }
    }
    cout << maxq.top() << '\n';
  }
  return 0;
}
```
  
[acmicpc.net/problem/1655]: https://acmicpc.net/problem/1655
