#include <stdio.h>

void mergeArrays(int arr1[], int size1, int arr2[], int size2, int mergedArr[]) {
    int i = 0, j = 0, k = 0;

    // Traverse both arrays and compare elements
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j])
            mergedArr[k++] = arr1[i++];
        else
            mergedArr[k++] = arr2[j++];
    }

    // Copy the remaining elements of arr1[], if any
    while (i < size1)
        mergedArr[k++] = arr1[i++];

    // Copy the remaining elements of arr2[], if any
    while (j < size2)
        mergedArr[k++] = arr2[j++];
}

int main() {
    int size1, size2;

    // Input the sizes of the two arrays
    printf("Enter the size of the first array: ");
    scanf("%d", &size1);

    printf("Enter the size of the second array: ");
    scanf("%d", &size2);

    int arr1[size1], arr2[size2], mergedArr[size1 + size2];

    // Input the elements of the first array
    printf("Enter the elements of the first array in sorted order:\n");
    for (int i = 0; i < size1; i++)
        scanf("%d", &arr1[i]);

    // Input the elements of the second array
    printf("Enter the elements of the second array in sorted order:\n");
    for (int i = 0; i < size2; i++)
        scanf("%d", &arr2[i]);

    // Merge the arrays
    mergeArrays(arr1, size1, arr2, size2, mergedArr);

    // Display the merged array
    printf("Merged Array:\n");
    for (int i = 0; i < size1 + size2; i++)
        printf("%d ", mergedArr[i]);

    return 0;
}
