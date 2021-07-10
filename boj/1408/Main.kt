fun main() {
  val now: String = readLine()!!;
  val start: String = readLine()!!;
  var res: String = "";

  val nowhms: IntArray = now.split(":".toRegex()).map{it.toInt()}.toIntArray();
  val starthms: IntArray = start.split(":".toRegex()).map{it.toInt()}.toIntArray();

  if (nowhms[2] > starthms[2]) {
    starthms[1]--;
    starthms[2] += 60;
  }
  if (nowhms[1] > starthms[1]) {
    starthms[0]--;
    starthms[1] += 60;
  }
  var h: Int = starthms[0] - nowhms[0];
  if (h < 0)
    h += 24;
  val hs: String = h.toString();
  val m: String = (starthms[1] - nowhms[1]).toString();
  val s: String = (starthms[2] - nowhms[2]).toString();

  res += "${if (hs.length < 2) "0$hs" else hs}:";
  res += "${if (m.length < 2) "0$m" else m}:";
  res += "${if (s.length < 2) "0$s" else s}";
  println(res);
}
