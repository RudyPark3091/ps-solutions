fun main() {
  val nk: List<Int> = readLine()!!.split(" ".toRegex()).map{it.toInt()};
  val n: Int = nk[0];
  val k: Int = nk[1];

  var arr: IntArray = IntArray(101);
  var dp: IntArray = IntArray(10001);
  dp[0] = 1;

  for (i in 1..n) {
    arr[i] = readLine()!!.toInt();
  }

  for (i in 1..n) {
    for (j in 1..k) {
      if (j >= arr[i]) {
        dp[j] = dp[j - arr[i]] + dp[j];
      }
    }
  }

  println(dp[k]);
}
