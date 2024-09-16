#include<stdio.h>

int a[10], currentsize = 0, size;

// Function prototypes
int display(int *a);
int insert(int *a);
int deleteElement(int *a);  // Changed delete to deleteElement
int search(int *a);
int sort(int *a);
int fullorempty();

int main(){
    int choice;

    printf("Enter the size of the array (max 10): ");
    scanf("%d", &size);

    if(size > 10 || size <= 0) {
        printf("Invalid size. Please enter a size between 1 and 10.\n");
        return 1;
    }

    for(int i = 0; i < size; i++){
        printf("Enter the element %d: ", i+1);
        scanf("%d", &a[i]);
        currentsize++;
    }    

    printf("To perform operations, enter any one option\n"); 
    printf("1. To display\n"); 
    printf("2. To Insert\n");
    printf("3. To Delete\n");
    printf("4. To Search\n");  
    printf("5. To Sort\n"); 
    printf("0. To exit\n"); 
    
    do {
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                display(a);
                break;
            case 2:
                insert(a);
                break;  
            case 3:
                deleteElement(a);  // Updated function name here
                break; 
            case 4:
                search(a);
                break;
            case 5:
                sort(a);
                break;  
            case 0:
                printf("You Exited👍\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 0);

    return 0;
}

// Function to check if array is full or empty  
int fullorempty() {       
    if(currentsize == size) {
        return 1;  // Array is full
    } else if(currentsize == 0) {
        return 2;  // Array is empty
    } else {
        return 0;  // Array is neither full nor empty
    }
}

// To insert an element in a specific position
int insert(int *a) {  
    int element, pos;
    if(fullorempty() == 1) {
        printf("Array is Full, Cannot Insert!\n");
    } else {  
        printf("Enter the element to insert: ");
        scanf("%d", &element);
        printf("Enter the position to insert (1 to %d): ", currentsize + 1);
        scanf("%d", &pos);
        
        if(pos < 1 || pos > currentsize + 1) {
            printf("Invalid Position\n");
        } else {  
            for(int i = currentsize; i >= pos; i--) {
                a[i] = a[i-1];
            }
            a[pos-1] = element;
            currentsize++;
            display(a);
        }
    }   
    return 0;
}

// To delete an element from a specific position
int deleteElement(int *a) {  // Changed function name from delete to deleteElement
    int pos;
    if(fullorempty() == 2) {
        printf("Array is Empty, You can't delete\n");
    } else {
        printf("Enter the position to delete (1 to %d): ", currentsize);
        scanf("%d", &pos);
        if(pos < 1 || pos > currentsize) {
            printf("Invalid Position\n");
        } else {        
            for(int i = pos-1; i < currentsize-1; i++) {
                a[i] = a[i+1];
            }
            currentsize--;
            display(a);
        } 
    }
    return 0;
}

// To search for an element in the array
int search(int *a) {
    if(fullorempty() == 2) {
        printf("The array is empty, You can't search\n");
    } else {
        int searchElement, found = 0;
        printf("Enter the element to search: ");
        scanf("%d", &searchElement);

        for(int i = 0; i < currentsize; i++) {
            if(a[i] == searchElement) {
                printf("The element is in %d(st/nd/rd/th) position.\n", i + 1);
                found = 1;
                break;
            }
        }
        if(!found) {
            printf("Not found!\n");
        }
    }
    return 0;
}

// To display the array elements
int display(int *a) {
    printf("The elements are:\n");
    for(int i = 0; i < currentsize; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}

// To sort the array elements in ascending order
int sort(int *a) {
    int i, j, temp;
    if(fullorempty() == 2) {
        printf("The array is empty, Can't sort\n");
    } else {
        for(i = 0; i < currentsize - 1; i++) {
            for(j = i + 1; j < currentsize; j++) {
                if(a[i] > a[j]) {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
        printf("Sorted Array:\n");
        display(a);
    }
    return 0;
}