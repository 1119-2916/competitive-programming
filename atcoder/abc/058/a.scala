object Main extends App {
  val Array(a, b, c) = io.StdIn.readLine.split(" ").map(_.toInt)
  if (b - a == c - b) {
    println("YES")
  } else {
    println("NO")
  }
}
