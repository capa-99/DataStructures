//Cycle sort is an in-place, unstable sorting algorithm that is particularly useful when sorting arrays containing elements with a small range of values.
//The idea behind cycle sort is to divide the input array into cycles, where each cycle consists of elements that belong to the same position in the sorted output array. The algorithm then performs a series of swaps to place each element in its correct position within its cycle, until all cycles are complete and the array is sorted.

//Here’s a step-by-step explanation of the cycle sort algorithm:
//Start with an unsorted array of n elements.
//Initialize a variable, cycleStart, to 0.
//For each element in the array, compare it with every other element to its right. If there are any elements that are smaller than the current element, increment cycleStart.
//If cycleStart is still 0 after comparing the first element with all other elements, move to the next element and repeat step 3.
//Once a smaller element is found, swap the current element with the first element in its cycle. The cycle is then continued until the current element returns to its original position.
//Repeat steps 3-5 until all cycles have been completed.
//The array is now sorted.
//Cycle sort has a low memory footprint, as it sorts the array in-place and does not require additional memory for temporary variables or buffers. However, it can be slow in certain situations, particularly when the input array has a large range of values.
//It is optimal in terms of the number of memory writes. It minimizes the number of memory writes to sort (Each value is either written zero times or one time to its correct position.)
//Cycles can be visualized as a graph. There are n nodes and an edge directed from node i to node j if the element at i-th index must be present at j-th index in the sorted array. 
//One by one consider all cycles. First consider the cycle that includes the first element. Find the correct position of the first element, and place it at its correct position, say j. Consider the old value of arr[j] and find its correct position and keep doing this until all elements of the current cycle are placed at the correct position, i.e., we don’t come back to the cycle starting point.




