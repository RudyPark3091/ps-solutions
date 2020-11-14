fun getDist(a: List<Int>, b: List<Int>): Int {
  var dist: Int = (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
  return dist;
}

fun main() {
  var t: Int = readLine()!!.toInt();
  for (i in 1..t) {
    var l: List<Int> = readLine()!!.split(" ".toRegex()).map{it.toInt()};
    var dep: List<Int> = listOf(l[0], l[1]);
    var dest: List<Int> = listOf(l[2], l[3]);

    var res: Int = 0;
    var n: Int = readLine()!!.toInt();

    for (j in 1..n) {
      var coord: List<Int> = readLine()!!.split(" ".toRegex()).map{it.toInt()};
      if (getDist(coord, dep) < coord[2] * coord[2] && getDist(coord, dest) < coord[2] * coord[2]) {
        continue;
      }
      if (getDist(coord, dep) < coord[2] * coord[2]) {
        res++;
      } else if (getDist(coord, dest) < coord[2] * coord[2]) {
        res++;
      }
    }
    println(res);
  }
}
