import java.util.Scanner;

public class Main {
  static int n, m;
  static int[][] arr = new int[501][501];
  static int[][] dp = new int[501][501];
  static int[][] moves = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    n = sc.nextInt();
    m = sc.nextInt();

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        arr[i][j] = sc.nextInt();
        dp[i][j] = -1;
      }
    }

    System.out.println(solve(1, 1));
  }

  static int solve(int dx, int dy) {
    if (dx == n && dy == m)
      return 1;

    if (dp[dx][dy] == -1) {
      dp[dx][dy] = 0;

      for (int i = 0; i < 4; i++) {
        int nx = dx + moves[i][0];
        int ny = dy + moves[i][1];

        if (nx <= n && nx > 0 && ny <= m && ny > 0) {
          if (arr[dx][dy] > arr[nx][ny])
            dp[dx][dy] += solve(nx, ny);
        }
      }
    }

    return dp[dx][dy];
  }
}
