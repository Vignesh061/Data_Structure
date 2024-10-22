#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; // Key found, return index
        }
    }
    return -1; // Key not found
}

int main() {
    int size, key;

    // Getting the size of the array from the user
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size];

    // Getting the array elements from the user
    printf("Enter %d elements of the array:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Getting the key to search for
    printf("Enter the value to search: ");
    scanf("%d", &key);

    // Perform linear search
    int result = linearSearch(arr, size, key);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    return 0;
}
