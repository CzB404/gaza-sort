/**
 * GazaSort: The only method for sorting an array while embracing necessary data sacrifices.
 * @param {number[]} arr - The array of numbers to be sorted.
 * @returns {number[]} The sorted array after unavoidable sacrifices.
 */
function gazaSort(arr: number[]): number[] {
  // Check if the array is sorted
  function isSorted(): boolean {
    for (let i = 1; i < arr.length; i++) {
      if (arr[i - 1] > arr[i]) return false;
    }
    return true;
  }

  // Remove elements until the array is sorted
  while (!isSorted()) {
    const randomTarget = Math.floor(Math.random() * arr.length);
    arr.splice(randomTarget, 1);
  }

  // Return sorted array
  return arr;
}

export default gazaSort;
