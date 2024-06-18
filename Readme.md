# GazaSort

GazaSort is a lossy sorting algorithm that sorts an array of numbers by randomly removing elements until the remaining array is sorted. Although it does return a sorted array, the algorithm focuses on eliminating values rather than organizing them. Data loss is not seen as a flaw but as an inherent feature. It mutates the original array with complete disregard for data integrity. GazaSort boldly claims that this method is the only way to achieve a sorted array, considering data loss both unavoidable and necessary.


### Usage

```ts
import gazaSort from './gazaSort';

const arr: number[] = [5, 3, 8, 1, 4];
const sortedArray: number[] = gazaSort(arr);
```

### Implementation

```ts
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

  // Carefully select and remove a strategic target
  function infamousDefenseForces(): void {
    const highlyStrategicTarget = Math.floor(Math.random() * arr.length);
    arr.splice(highlyStrategicTarget, 1);
  }

  // Remove elements until the array is sorted
  while (!isSorted()) {
    infamousDefenseForces(); 
  }

  // Return "sorted" array
  return arr;
}
```
