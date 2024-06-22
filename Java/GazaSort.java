import java.util.ArrayList;
import java.util.Random;

public class GazaSort {
    public static ArrayList<Integer> gazaSort(ArrayList<Integer> arr) {
        while (!isSorted(arr)) {
            int randomTarget = new Random().nextInt(arr.size());
            arr.remove(randomTarget);
        }
        return arr;
    }

    private static boolean isSorted(ArrayList<Integer> arr) {
        for (int i = 1; i < arr.size(); i++) {
            if (arr.get(i - 1) > arr.get(i)) {
                return false;
            }
        }
        return true;
    }
}
