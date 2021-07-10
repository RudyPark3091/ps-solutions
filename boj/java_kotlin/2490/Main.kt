fun main(args: Array<String>) {
	for (i in 1..3) {
		val arr = readLine()!!.split(" ").map{ it.toInt() }.toList()
		var ones: Int = 0
		var zeros: Int = 0
		for (item in arr) {
			if (item == 1) ones++
			else zeros++
		}
		if (ones == 0) println("E")
		else if (ones == 1) println("C")
		else if (ones == 2) println("B")
		else if (ones == 3) println("A")
		else if (ones == 4) println("D")
	}
}
