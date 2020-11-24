import kotlin.math.abs;

fun main(args: Array<String>) {
	var arr: Array<IntArray> = Array(5, {IntArray(5)});
	
	for (i in 0..4) {
		arr[i] = readLine()!!.split(" ".toRegex()).map{it.toInt()}.toIntArray();
		if (1 in arr[i]) {
			println(abs(2-i) + abs(2 - arr[i].indexOf(1)));
		}
	}
}
