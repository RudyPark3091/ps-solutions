import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int[] arr = new int[501];
    int[][] dp = new int[501][501];
    int[] sum = new int[501];

    int t = Integer.parseInt(br.readLine());
    for (int i = 0; i < t; i++) {
      int k = Integer.parseInt(br.readLine());
      String s = br.readLine();
      StringTokenizer st = new StringTokenizer(s);
      for (int j = 1; j <= k; j++) {
        arr[j] = Integer.parseInt(st.nextToken());
        sum[j] = sum[j-1] + arr[j];
      }

      for (int x = 1; x < k; x++) {
        for (int y = 1; x + y <= k; y++) {
          int z = x + y;
          dp[y][z] = 2147483647;

          for (int w = y; w < z; w++) {
            dp[y][z] = Math.min(dp[y][z], dp[y][w] + dp[w+1][z] + sum[z] - sum[y-1]);
          }
        }
      }

      System.out.println(dp[1][k]);
    }
  }
}
