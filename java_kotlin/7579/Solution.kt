import kotlin.math.max;

fun main(args: Array<String>) {
	val (n, m) = readLine()!!.split(" ").map{it.toInt()};
	var arr: IntArray = readLine()!!.split(" ").map{it.toInt()}.toIntArray();
	var v: IntArray = readLine()!!.split(" ").map{it.toInt()}.toIntArray();
	val sum: Int = v.sum();
	var dp: IntArray = IntArray(sum);

	for (i in 0..n-1) {
		for (j in sum-1 downTo 0) {
			if (j - v[i] >= 0) {
				dp[j] = max(dp[j], dp[j-v[i]] + arr[i]);
			}
		}
	}

	for (i in 0..sum-1) {
		if (dp[i] >= m) {
			println(i);
			return;
		}
	}
}
