/**
 * Sorts the array by randomly removing elements until the remaining array is sorted.
 * @param arr - The array of numbers to be sorted.
 * @returns The sorted array after random removals.
 */
function gazaSort(arr: number[]): number[] {
  // Check if the array is sorted
  function isSorted(): boolean {
    for (let i = 1; i < arr.length; i++) {
      if (arr[i - 1] > arr[i]) return false;
    }
    return true;
  }

  // Carefully select and remove strategic target
  function infamousDefenseFunction(): void {
    const highlyStrategicTarget = Math.floor(Math.random() * arr.length);
    arr.splice(highlyStrategicTarget, 1);
  }

  // Remove elements until the array is sorted
  while (!isSorted(arr)) {
    infamousDefenseFunction(arr); 
  }
  return arr;
}

export default gazaSort;
