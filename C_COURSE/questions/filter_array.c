#include <stdio.h>
 
#define ARRAY_SIZE 10
 
int filterArray (char* originalArray, char* newArray, int arraySize);
void printArray(char arr[], int arr_size);

int main() {

    char originalArray[ARRAY_SIZE] = {5,7,2,6,-2,2,5,-6,8,3};
    char filteredArray[ARRAY_SIZE];

    printf("Size of original array: %d\n", ARRAY_SIZE);
    printf("Original array: ");
    printArray(originalArray, ARRAY_SIZE);

    int filteredArraySize = filterArray(originalArray, filteredArray, ARRAY_SIZE);
    
    printf("Size of filtered array: %d\n", filteredArraySize);
    printf("Filtered array: ");
    printArray(filteredArray, filteredArraySize);
    return 0;
}
 
/*
->  Parameters in:
        - arraySize: size of the original array.
        - originalArray: array of elements to be filtered.
->  Parameters out:
        - filteredArray: array of elements after filtering.
->  Return value:
        - size of the filtered array.
*/
int filterArray (char* originalArray, char* filteredArray, int arraySize) {
    int lastIndex = 0;
    int tempArr[256] = {0};
    for (int i=0; i<arraySize; i++) {
        tempArr[(unsigned char)originalArray[i]]++;
        if (tempArr[(unsigned char)originalArray[i]] == 1) {
            filteredArray[lastIndex] = originalArray[i];
            lastIndex++;
        }
    }
    return lastIndex;
}


void printArray(char arr[], int arr_size) {
    for (int i=0; i<arr_size; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}