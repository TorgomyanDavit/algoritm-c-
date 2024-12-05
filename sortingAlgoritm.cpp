#include <iostream>

void printNewArray(int arr[], int length) {
    for (int i = 0; i < length; ++i) {
        std::cout << arr[i] << ",";
    }
}

void BubbleSort(int* arr,int length) {
    bool finish = false;

    do {
        finish = false;

        for(int i = 0; i < length; i++) {
            int currElement = arr[i];
            int nextElement = arr[i + 1];

            if(currElement > nextElement) {
                arr[i] = nextElement;
                arr[i + 1] = currElement;
                finish = true;
            }
        }

    } while(finish);


    printNewArray(arr,length);
}

void SelectionSort(int* arr,int length) {

    for(int i = 0;i < length;i++) {
        int minIndex = i;

        for(int i2 = 0;i2 < length;i2++) {
            int currentElement = arr[i2];
            int nextElement = arr[i2 + 1];

            if(nextElement < currentElement) {
                minIndex = i2 + 1;
            }

        };

        if(minIndex != i) {
            int temp = arr[minIndex];
            arr[minIndex] = arr[i]; 
            arr[i] = temp;
        };

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

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to implement quicksort
void QuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        QuickSort(arr, low, pivotIndex - 1);
        QuickSort(arr, pivotIndex + 1, high);
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

int sortingAlgoritm() {
    /** Array  exercize*/
    std::cout << "Sorting algoritm start";
    int arr[] = {5,4,3,2,1};
    int length = sizeof(arr) / sizeof(int);

    // BubbleSort(arr,length);
    // SelectionSort(arr,length);
    // InsertionSort(arr,length);
    // QuickSort(arr, 0, length - 1);
    // mergeSort(arr, 0, length - 1);

    return 0; 
}


// Bubble Sort + ancnum e hertakanutyamb ev amenamec element swapi ognuyamb brtuma araj; Time Complexity O(n^2)
// Selection Sort + gtnum e amenapoqr element@ ev qacuma araj, heto tenc sharunakabar minchev avartvi indexner@; Time Complexity O(n^2) 
// quickSort +  bajanum e  Pivot, Left and right maseri ev anyndhat nuyn@ minchev verj, and finishily concat its all recurioon  O(n^2)
// Insertion Sort: + stugum e hetevi ev dimacin@ ete meca het het gnalov noric krknuma ev mecer@ qay ar qayl het qaylerov dasavoruma hertakanutyamb O(n^2)
// Merge Sort: + merge sort@ ogtagorcvum e shat ,  O(n log n).   
// Heap Sort: 
// Counting Sort:
// Radix Sort:
// Bucket Sort:
// Tim Sort:
// Cocktail Sort:
// Gnome Sort: 