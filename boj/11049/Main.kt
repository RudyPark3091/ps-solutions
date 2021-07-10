import kotlin.math.min;

fun main() {
  var dp: Array<IntArray> = Array(501, {IntArray(501)});
  var arr: Array<IntArray> = Array(501, {IntArray(2)});
  val n: Int = readLine()!!.toInt();

  for (i in 1..n) {
    arr[i] = readLine()!!.split(" ".toRegex()).map{it.toInt()}.toIntArray();
  }

  for (i in 1..n-1) {
    for (j in 1..n-i) {
      val k: Int = i + j;
      dp[j][k] = 2147483647;

      for (w in j..k-1) {
        dp[j][k] = min(dp[j][k], dp[j][w] + dp[w+1][k] + arr[j][0] * arr[w][1] * arr[k][1]);
      }
    }
  }

  println(dp[1][n]);
}
