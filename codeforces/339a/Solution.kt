fun main(args: Array<String>) {
	val arr: IntArray = readLine()!!.split("+").map{it.toInt()}.toIntArray();
	arr.sort();
	println(arr.joinToString("+"));
}
