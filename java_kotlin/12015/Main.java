import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(br.readLine());
    int[] lcs = new int[n];
    
    StringTokenizer st = new StringTokenizer(br.readLine());

    int cnt = 0;
    for (int i = 0; i < n; i++) {
      int num = Integer.parseInt(st.nextToken());
      if (cnt == 0 || num > lcs[cnt - 1]) {
        lcs[cnt] = num;
        cnt++;
      } else {
        lcs[lower_bound(lcs, cnt, num)] = num;
      }
    }

    System.out.println(cnt);
  }

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

}
