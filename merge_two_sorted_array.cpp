#include<iostream>
using namespace std;

// we have to make sure that vector is passed by referenc
// because the vector stores the answerwhen it is called
void mergeSortedArray(int arr[], int size_1, int brr[], int size_2, vector<int> &solve){
    int i = 0, j = 0; // two-pointer approach

    /* i & j should be inside bounds */
    while(i<size_1 && j<size_2){
        /* when is 'i' is smaller then we add that first to make it sorted */
        if(arr[i] < brr[j]){
            solve.push_back(arr[i]);
            i++;
        }
        else{
            solve.push_back(brr[j]);
            j++;
        }
    }

    /* after exiting loop there are two cases: handling uncompared part */
    // case-1: arr contains elements (when arr has more elements than brr)
    while(i<size_1){
        solve.push_back(arr[i]);
        i++;
    }
    // case-2: brr contains elements (when brr has more elements than arr)
    while(j<size_2){
        solve.push_back(brr[j]);
        j++;
    }   
}

int main(){
    int arr[] = {10,30,50,70};
    int size_arr = sizeof(arr)/sizeof(arr[0]);

    int brr[] = {20,40,60,80,90,100};
    int size_brr = sizeof(brr)/sizeof(brr[0]);

    vector<int> solve;
    mergeSortedArray(arr, size_arr, brr, size_brr, solve);

    cout<<"Post merge: ";
    for(auto num:solve){
        cout<<num<<" ";
    }
}