import java.util.StringTokenizer;
import kotlin.math.min;

fun main() {
  var arr: IntArray = IntArray(501);
  var sum: IntArray = IntArray(501);
  var dp: Array<IntArray> = Array(501, {IntArray(501)});

  val t: Int = readLine()!!.toInt();
  for (i in 0..t-1) {
    val k: Int = readLine()!!.toInt();
    var st: StringTokenizer = StringTokenizer(readLine()!!);

    for (j in 1..k) {
      arr[j] = st.nextToken().toInt();
      sum[j] = sum[j-1] + arr[j];
    }

    for (x in 1..k-1) {
      for (y in 1..k-x) {
        val z: Int = x + y;
        dp[y][z] = 2147483647;

        for (w in y..z-1) {
          dp[y][z] = min(dp[y][z], dp[y][w] + dp[w+1][z] + sum[z] - sum[y-1]);
        }
      }
    }

    println(dp[1][k]);
  }
}
