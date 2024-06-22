package main

import (
    "math/rand"
    "time"
)

func gazaSort(arr []int) []int {
    for !isSorted(arr) {
        rand.Seed(time.Now().UnixNano())
        arr = append(arr[:rand.Intn(len(arr))], arr[rand.Intn(len(arr))+1:]...)
    }
    return arr
}

func isSorted(arr []int) bool {
    for i := 1; i < len(arr); i++ {
        if arr[i-1] > arr[i] {
            return false
        }
    }
    return true
}
