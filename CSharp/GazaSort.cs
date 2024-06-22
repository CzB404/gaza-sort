using System;
using System.Collections.Generic;

public class GazaSort {
    public static List<int> Sort(List<int> arr) {
        Random rnd = new Random();
        while (!IsSorted(arr)) {
            arr.RemoveAt(rnd.Next(arr.Count));
        }
        return arr;
    }

    private static bool IsSorted(List<int> arr) {
        for (int i = 1; i < arr.Count; i++) {
            if (arr[i - 1] > arr[i]) {
                return false;
            }
        }
        return true;
    }
}
