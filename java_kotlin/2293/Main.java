import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int k = sc.nextInt();

    int[] arr = new int[101];
    int[] dp = new int[10001];
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
      arr[i] = sc.nextInt();

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= k; j++) {
        if (j >= arr[i])
          dp[j] = dp[j - arr[i]] + dp[j];
      }
    }

    System.out.println(dp[k]);
  }
}
