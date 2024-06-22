function gazaSort(array $arr): array {
    while (!isSorted($arr)) {
        array_splice($arr, rand(0, count($arr) - 1), 1);
    }
    return $arr;
}

function isSorted(array $arr): bool {
    for ($i = 1; $i < count($arr); $i++) {
        if ($arr[$i - 1] > $arr[$i]) {
            return false;
        }
    }
    return true;
}
