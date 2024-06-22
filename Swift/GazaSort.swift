import Foundation

func gazaSort(_ arr: inout [Int]) -> [Int] {
    while !isSorted(arr) {
        arr.remove(at: Int.random(in: 0..<arr.count))
    }
    return arr
}

func isSorted(_ arr: [Int]) -> Bool {
    for i in 1..<arr.count {
        if arr[i-1] > arr[i] {
            return false
        }
    }
    return true
}
