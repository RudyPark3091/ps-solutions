fun main(args: Array<String>) {
	val n: Int = readLine()!!.toInt()
	var s: String = readLine()!!
	var res: Int = 0
	
	for (i in 1..n-1) {
		if (s[i] == s[i-1]) {
			res += 1
		}
	}

	println(res)
}
