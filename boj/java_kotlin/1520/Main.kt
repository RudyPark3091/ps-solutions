import java.util.Scanner;

var n: Int = 0;
var m: Int = 0;
var arr: Array<IntArray> = Array(501, {IntArray(501)});
var dp: Array<IntArray> = Array(501, {IntArray(501, {-1})}); 
var moves: Array<IntArray> = arrayOf(intArrayOf(1, 0), intArrayOf(0, 1), intArrayOf(-1, 0), intArrayOf(0, -1));

fun solve(dx: Int, dy: Int): Int {
  if (dx == n && dy == m)
    return 1;

  if (dp[dx][dy] == -1) {
    dp[dx][dy] = 0;

    for (i in 0..3) {
      var nx: Int = dx + moves[i][0];
      var ny: Int = dy + moves[i][1];

      if (nx <= n && nx > 0 && ny <= m && ny > 0) {
        if (arr[dx][dy] > arr[nx][ny])
          dp[dx][dy] += solve(nx, ny);
      }
    }
  }

  return dp[dx][dy];
}

fun main() {
  val sc: Scanner = Scanner(System.`in`);
  n = sc.nextInt();
  m = sc.nextInt();
  for (i in 1..n) {
    for (j in 1..m) {
      arr[i][j] = sc.nextInt();
      dp[i][j] = -1;
    }
  }

  println(solve(1,1));
}
