#include<iostream>
using namespace std;

// merge function
void merge(int arr[], int start, int end, int mid){
    // ========== length of left and right after mid point ==========
    int leftLength = mid - start + 1;
    int rightLength = end - mid;

    // create new array: this is a good practice using heap memory
    int *leftArray = new int[leftLength];
    int *rightArray = new int[rightLength];

    // ========== fill and copy left and right arrays ==========
    // copy original arrays values
    int index = start; // represents original array index
    // copying into left array
    for(int i=0; i<leftLength; i++){
        leftArray[i] = arr[index];
        index++;
    }
    // copying into right array
    index = mid + 1; // moving to right: not needed just for understanding
    for(int i=0; i<rightLength; i++){
        rightArray[i] = arr[index];
        index++;
    }

    /*========== merge logic ==========*/
    int leftIndex = 0, rightIndex = 0; // two pointers
    int mainArrayIndex = start; // index of main array

    // inside bounds check
    while(leftIndex < leftLength && rightIndex < rightLength){
        if(leftArray[leftIndex] < rightArray[rightIndex]){
            arr[mainArrayIndex] = leftArray[leftIndex];
            leftIndex++;
            mainArrayIndex++;
        }
        else{
            arr[mainArrayIndex] = rightArray[rightIndex];
            rightIndex++;
            mainArrayIndex++;
        }
    }
    
    // handling the remaining two cases after exit loop there are two cases: handling uncompared part */
    while(leftIndex < leftLength){
        arr[mainArrayIndex] = leftArray[leftIndex];
        leftIndex++;
        mainArrayIndex++;
    }
    
    while(rightIndex < rightLength){
        arr[mainArrayIndex] = rightArray[rightIndex];
        rightIndex++;
        mainArrayIndex++;
    }

    /* ============ delete heap memory: optimisation ============ */
    delete[] leftArray;
    delete[] rightArray;
}


// merging an array which was initially not sorted
/* using binary search & recursion */
void mergeSort(int arr[], int start, int end){
    // base case
    if(start >= end){ return; }

    // calculating mid
    int mid = (start) + (end - start)/2;

    // left side
    mergeSort(arr, start, mid);
    // right side
    mergeSort(arr, mid+1, end);

    // merge function call: adding both parts
    merge(arr, start, end, mid);
}

int main(){
    int arr[] = {10,30,50,60,80,110,150,20};
    int size = sizeof(arr)/sizeof(arr[0]);
    int start = 0, end = size - 1;

    mergeSort(arr, start, end);
    cout<<"Merge Sort logic: ";
    for(auto num: arr){
        cout<<num<<" ";
    }
}