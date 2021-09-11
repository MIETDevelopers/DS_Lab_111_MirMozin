//Name: Mir Mozin
//Assignment 2
#include <stdio.h>
#include <time.h>

//Function prototypes
void bubbleSort(int [], int); 
void mergeSort(int [], int, int);
void merge(int [], int, int, int);
void display(int *, int);

//Main function
int main(){
    int max = 10, arrBubble[10] = {1, 3, 42, 2, 41, 66, 66, 33, 98, 0};
    int arrMerge[10] = {1, 3, 42, 2, 41, 66, 66, 33, 98, 0};
    //Calculating the time taken
    //For bubble sort
    clock_t time1=clock();
    bubbleSort(arrBubble, max);
    printf("Sorted array: ");
    display(arrBubble, max);
    sleep(1); //Delay for 1sec
    time1=clock()-time1;
    double time_taken_by_bubble_sorting = ((double)time1)/CLOCKS_PER_SEC;
    printf("Bubble sort took '%f' seconds to execute!\n", time_taken_by_bubble_sorting);
    printf("\n");

    //For merge sort
    time1 = clock();
    mergeSort(arrMerge, 0, (max- 1));
    printf("Sorted array: ");
    display(arrMerge , max);
    sleep(1); //Delay for 1sec
    time1 = clock() - time1;
    double time_taken_by_merge_sorting = ((double)time1)/CLOCKS_PER_SEC;
    printf("Merge sort took '%f' seconds to execute!\n", time_taken_by_merge_sorting);
    printf("\n");
    return 0;
}

//Bubble sorting the array
void bubbleSort(int a[], int size){
    int temp;
    for (int i=0; i<size-1; i++){
        for (int j = 0; j < size - (i + 1); j++){
            if (a[j] > a[j + 1]){
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}   

//Used for displaying the sorted arrays
void display(int *arr, int size){
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

//Int left is for the left index and int right is for the right index of the array to be sorted
void mergeSort(int a[], int left, int right){
    if (left < right){
        //Avoids overflow for large left
        int m = left + (right - left) / 2;
        //Sorting the first and second halves
        mergeSort(a, left, m);
        mergeSort(a, m + 1, right);
        merge(a, left, m, right);
    }
}

void merge(int a[], int left, int m, int right){
    int i, j, k;
    int n1 = m - left + 1;
    int n2 = right - m;

    //Creating temporary arrays
    int tempL[n1], tempR[n2]; 

    //Copying data to the temporary arrays
    for (i = 0; i < n1; i++)
        tempL[i] = a[left + i];
    for (j = 0; j < n2; j++)
        tempR[j] = a[m + 1 + j];

    //Merging the temporary arrays back
    //Inital indexes
    i = 0;    //First sub array
    j = 0;    //Second sub array
    k = left; //Merged sub array

    while (i < n1 && j < n2){
        if (tempL[i] <= tempR[j]){
            a[k] = tempL[i];
            i++;
        }
        else{
            a[k] = tempR[j];
            j++;
        }
        k++;
    }
    //Copying the remaining elements of tempL[]
    while (i < n1){
        a[k] = tempL[i];
        i++;
        k++;
    }

    //Copying the remaining elements of tempR[]
    while (j < n2){
        a[k] = tempR[j];
        j++;
        k++;
    }
}

/*
Merge Sort is taken into consideration to be one of the fastest sorting algorithms.
It is a bit extra complicated than Bubble Sort but it's far more efficient.
The concept of Merge Sort is to divide the data set into smaller data units, sort the ones smaller, and then merge them together.
*/