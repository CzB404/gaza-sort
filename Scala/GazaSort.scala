import scala.util.Random

def gazaSort(arr: Array[Int]): Array[Int] = {
    while (!isSorted(arr)) {
        val idx = Random.nextInt(arr.length)
        arr.patch(idx, Nil, 1)
    }
    arr
}

def isSorted(arr: Array[Int]): Boolean = {
  (0 until arr.length - 1).forall(i => arr(i) <= arr(i + 1))
}
