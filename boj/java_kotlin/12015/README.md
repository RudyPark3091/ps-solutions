## Java로 구현한 lower_bound 함수
c++ algorithm stl의 lower_bound() 에 대응됨   
``` java
private static int lower_bound(int[] arr, int size, int target) {
  int a = 0;
  int b = size;
  int mid = 0;
  
  while (a < b) {
    mid = (a + b) / 2;
    
    if (arr[mid] >= target) {
      b = mid;
    } else {
      a = mid + 1;
    }
  }

  return a;
}
```
