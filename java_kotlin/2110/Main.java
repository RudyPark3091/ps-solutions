import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {

  static int n, c;
  static int[] arr;
  
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    String s = br.readLine();
    StringTokenizer st = new StringTokenizer(s);

    n = Integer.parseInt(st.nextToken());
    c = Integer.parseInt(st.nextToken());

    arr = new int[n];

    for (int i = 0; i < n; i++) {
      arr[i] = Integer.parseInt(br.readLine());
    }

    Arrays.sort(arr);
    solve(1,  arr[n-1] - arr[0]);
  }

  public static void solve(int a, int b) {
    int mid = 0;
    int res = 0;

    while (a <= b) {
      mid = (a + b) / 2;
      int cnt = 1;
      int prev = 0;

      for (int i = 1; i < n; i++) {
        if (arr[i] - arr[prev] >= mid) {
          prev = i;
          cnt++;
        }
      }

      if (cnt < c) {
        b = mid - 1;
      } else {
        a = mid + 1;
        res = Math.max(res, mid);
      }
    }

    System.out.println(res);
  }

}
