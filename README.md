## Explanation
<h5> Codebase-1 </h5>
<ul>
  <li> Here, we use a two-pointer approach where we have 'i' for the first array and 'j' for the second array. </li>
  <li> Comparing i>j & j>i and moving it incrementally. Once covered, we copy the remaining elements to the main array. </li>
</ul>

```cpp
while(i<size_1 && j<size_2){
    if(arr[i] < brr[j]){
        solve.push_back(arr[i]);
        i++;
    }
    else{
        solve.push_back(brr[j]);
        j++;
    }
}
```

<h5> Codebase-2 </h5>
<ul>
  <li> Here, we have 2 functions: Merging and Divide-Conquer and Sorting. </li>
  <li> In the 1st function, the first is for dividing into a left-right array by coping the array as we divide then merging back to the main array. </li>
  <li> In the 2nd function, we use a binary search approach to sort the elements. </li>
</ul>

```cpp
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
```
