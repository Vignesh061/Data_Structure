#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int size, int key) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if key is present at mid
        if (arr[mid] == key) {
            return mid; // Key found, return index
        }

        // If key is greater, ignore the left half
        if (arr[mid] < key) {
            left = mid + 1;
        }
        // If key is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }

    return -1; // Key not found
}

int main() {
    int size;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    
    int arr[size]; // Declare the array with the specified size

    printf("Enter %d elements of the array \n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]); // Input each element
    }

    int key;
    printf("Enter the value to search: ");
    scanf("%d", &key); // Input the search key

    // Perform binary search
    int result = binarySearch(arr, size, key);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    return 0;
}
