use rand::Rng;

fn gaza_sort(mut arr: Vec<i32>) -> Vec<i32> {
    while !is_sorted(&arr) {
        let mut rng = rand::thread_rng();
        let idx = rng.gen_range(0..arr.len());
        arr.remove(idx);
    }
    arr
}

fn is_sorted(arr: &[i32]) -> bool {
    arr.windows(2).all(|w| w[0] <= w[1])
}
