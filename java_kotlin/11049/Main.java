import java.util.Scanner;

public class Main {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    int[][] dp = new int[501][501];
    int[][] arr = new int[501][2];

    int n = sc.nextInt();
    for (int i = 1; i <= n; i++) {
      arr[i][0] = sc.nextInt();
      arr[i][1] = sc.nextInt();
    }

    for (int i = 1; i < n; i++) {
      for (int j = 1; i + j <= n; j++) {
        int k = i + j;
        dp[j][k] = 2147483647;

        for (int w = j; w < k; w++) {
          dp[j][k] = Math.min(dp[j][k], dp[j][w] + dp[w+1][k] + arr[j][0] * arr[w][1] * arr[k][1]);
        }
      }
    }

    System.out.println(dp[1][n]);
  }
}
