## Problem
사용 연산:   
* 3으로 나눈다   
* 2로 나눈다   
* 1을 뺀다   
N을 입력받아 1으로 만드는 연산의 갯수의 최솟값를 출력한다.   
##### 입력: 정수 N (1 <= N <= 1000000)
##### 출력: 연산의 개수의 최솟값   

## Example
n = 4   
4 -> 2 -> 1 : 출력 - 3   
   
n = 12   
12 -> 4 -> 2 -> 1 : 출력 - 3   
   
n = 5   
5 -> 4 -> 2 -> 1 : 출력 - 3   
   
n = 15   
15 -> 5 -> 4 -> 2 -> 1 : 출력 - 5   
   
큰 수에서 연산을 하게 되면 작은 수가 나오는 패턴을 보인다.   
이를 실마리로 dp 알고리즘을 구현한다.   

## Logic Flow
크기 n+1의 배열을 선언한다.   
arr[i]에는 i를 만드는데 필요한 연산수의 최솟값이 들어간다.   
배열의 첫번째, 두번째, 세번째, 네번째 원소는 각각 0,0,1,1 으로 초기화한다.   
왜냐하면 n=1 -> 출력:1 , 2 -> 1 , 3 -> 1 로 이미 정해져있기 때문이다.   
4부터 n까지 iteration을 돌린다. (Bottom-Up 방식)   
arr[i] 에는 arr[i/2] + 1 을 저장하면된다.   
근데 최솟값이 들어가야되므로
``` cpp
arr[i] = min(arr[i-2], arr[i/1]) + 1
```
이 더 정확하다.   
만약 2와 3 둘다 나누어떨어지지 않는다면 이전 배열값에 1을 더한값을 저장한다.   
왜냐하면 그냥 1을 더하면 그 수가 나오기 때문이다.   
iteration이 끝나면 n번째 요소를 출력한다.   

## Source Code
``` cpp
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1000001] = {0, 0, 1, 1,};

int main() {
    cin >> n;

    for (int i = 4; i <= n; i++) {
        if (i % 2 != 0 && i % 3 != 0) { arr[i] = arr[i-1] + 1; }
        else if (i % 3 != 0) { arr[i] = min(arr[i/2], arr[i-1]) + 1; }
        else if (i % 2 != 0) { arr[i] = min(arr[i/3], arr[i-1]) + 1; }
        else { arr[i] = min(arr[i-1], min(arr[i/2], arr[i/3])) + 1; }
    }

    cout << arr[n] << '\n';
    return 0;
}
```
   
