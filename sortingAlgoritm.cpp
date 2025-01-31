
#include <iostream>

void printNewArray(int arr[], int length) {
    for (int i = 0; i < length; ++i) {
        std::cout << arr[i] << ",";
    }
}

void BubbleSort(int *arr,int length) {
    bool finish = true;

    while (finish){
        finish = false;
        for(int i = 0; i < length;i++) {
            int currentElement = arr[i];
            int nextElement = arr[i + 1];
            if(currentElement > nextElement) {
                arr[i] = nextElement;
                arr[i + 1] = currentElement;
                finish = true;
            }
        }        
    }
    printNewArray(arr,length);
}

void SelectionSort(int* arr,int length) {

    for(int i = 0;i < length;i++) {
        int minIndex = i;

        for (int j = i + 1; j < length; j++) {
            int nextElement = arr[j];
            int currentElement = arr[minIndex];

            if (nextElement < currentElement) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }

    printNewArray(arr,length);
}

void InsertionSort(int* arr,int length) {
    for(int i = 1; i < length; i++) {
        int nextElement = arr[i];
        int prevElementIndex = i - 1;

        while (prevElementIndex >= 0 && arr[prevElementIndex] > nextElement){
            arr[prevElementIndex + 1] = arr[prevElementIndex];
            prevElementIndex--;
        }

        arr[prevElementIndex + 1] = nextElement;
    }

    printNewArray(arr,length);
}

void quickSort(int* arr, int size) {
    if (size <= 1) {
        return; // Base case: already sorted
    }

    int pivot = arr[0];
    int less[size];
    int equal[size]; 
    int greater[size];
    int lessCount = 0, equalCount = 0, greaterCount = 0;

    // Partition the array
    for (int i = 0; i < size; i++) {
        if (arr[i] < pivot) {
            less[lessCount++] = arr[i];
        } else if (arr[i] == pivot) {
            equal[equalCount++] = arr[i];
        } else {
            greater[greaterCount++] = arr[i];
        }
    }

    // Recursively sort the less and greater arrays
    quickSort(less, lessCount);
    quickSort(greater, greaterCount);

    // Combine results back into the original array
    int index = 0;

    // Add sorted less array
    for (int i = 0; i < lessCount; i++) {
        arr[index++] = less[i];
    }

    // Add equal array
    for (int i = 0; i < equalCount; i++) {
        arr[index++] = equal[i];
    }

    // Add sorted greater array
    for (int i = 0; i < greaterCount; i++) {
        arr[index++] = greater[i];
    }
}


// Function to merge two sorted subarrays into a single sorted array
void merge(int array[], int left, int middle, int right) {
    int leftSize = middle - left + 1;   // Size of the left subarray
    int rightSize = right - middle;      // Size of the right subarray

    // Create temporary arrays for the left and right subarrays
    int leftArray[leftSize], rightArray[rightSize];

    // Copy data to temporary arrays leftArray[] and rightArray[]
    for (int i = 0; i < leftSize; i++)
        leftArray[i] = array[left + i];

    for (int j = 0; j < rightSize; j++)
        rightArray[j] = array[middle + 1 + j];

    // Merge the temporary arrays back into array[left..right]
    int i = 0;  // Initial index of left subarray
    int j = 0;  // Initial index of right subarray
    int k = left;  // Initial index of merged subarray

    while (i < leftSize && j < rightSize) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArray[], if any
    while (i < leftSize) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArray[], if any
    while (j < rightSize) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

// Function to perform merge sort on the array
void mergeSort(int array[], int left, int right) {
    if (left < right) {
        // Find the middle point
        int middle = left + (right - left) / 2;

        // Recursively sort the first and second halves
        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);

        // Merge the sorted halves
        merge(array, left, middle, right);
    }
}

int main() {
    /** Array  exercize*/
    std::cout << "Sorting algoritm start";
    int arr[] = {2, 1, 3, 5, 4};
    int length = sizeof(arr) / sizeof(int);

    // BubbleSort(arr,length);
    // SelectionSort(arr,length);
    // InsertionSort(arr,length);

    // quickSort(arr,length);

    int left = 0;
    int right = length - 1;
    mergeSort(arr, left, right);
    printNewArray(arr,length);


    return 0; 
}


/** Bubble Sort repeatedly compares adjacent elements in an array and swaps them 
 if they are in the wrong order. This process continues in multiple passes until 
 no swaps are needed, meaning the array is sorted. During each pass, larger elements 
 "bubble up" to their correct positions, starting from the beginning of the array.
*/

/**
    Selection Sort is a simple sorting algorithm that repeatedly selects the smallest (or largest) element from the unsorted portion of the array and places it at the beginning of the sorted portion.
    Time Complexity:
    Best case: O(n²)
    Worst case: O(n²)
    Average case: O(n²)
    Space Complexity: O(1)
*/

/**
 * Insertion Sort
    Insertion Sort is a simple sorting algorithm that builds the sorted array one element at a time. It iteratively takes an element from the unsorted portion and places it in the correct position within the sorted portion.
    Time Complexity:
    Best case (sorted array): O(n)
    Worst case: O(n²)
    Average case: O(n²)
    Space Complexity: O(1)
*/

// quickSort +  bajanum e  Pivot, Left and right maseri ev anyndhat nuyn@ minchev verj, and finishily concat its all recurioon  O(n^2)
// Selection Sort + gtnum e amenapoqr element@ ev qacuma araj, heto tenc sharunakabar minchev avartvi indexner@; Time Complexity O(n^2) 
// Insertion Sort: + stugum e hetevi ev dimacin@ ete meca het het gnalov noric krknuma ev mecer@ qay ar qayl het qaylerov dasavoruma hertakanutyamb O(n^2)
// Merge Sort: + merge sort@ ogtagorcvum e shat ,  O(n log n).   
// Heap Sort: 
// Counting Sort:
// Radix Sort:
// Bucket Sort:
// Tim Sort:
// Cocktail Sort:
// Gnome Sort: 