import kotlin.random.Random

fun gazaSort(arr: MutableList<Int>): List<Int> {
    while (!isSorted(arr)) {
        arr.removeAt(Random.nextInt(arr.size))
    }
    return arr
}

fun isSorted(arr: List<Int>): Boolean {
    return arr.zipWithNext().all { (a, b) -> a <= b }
}
