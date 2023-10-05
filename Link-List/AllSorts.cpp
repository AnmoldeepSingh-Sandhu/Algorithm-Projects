#include <iostream>
#include <vector>


void sel_sort(std::vector<int> & v){

    std::cout<< "Selection Sort = ";

    for(unsigned i = 0; i < v.size();i++){

        int m = i;
        for(unsigned j = i+1; j < v.size();j++){

            if(v[m] > v[j]){
                m = j;
            }
        }

        int temp = v[i];
        v[i] = v[m];
        v[m] = temp;
        std::cout<< v[i]<<",";

    }

    std::cout<< std::endl;
}


void in_sort(std::vector<int> & A, int n){

    if(n == 1){
        return;
    }
    in_sort(A,n-1);
    int i;
    int temp = A[n-1];
    i = n-1;


    // Here's where the insertion sort happens.
    // We're taking the last element (A[n-1]) and placing it in its correct sorted position
    // within the first n elements.
    while(i>0 && A[i-1] > temp){
        A[i] = A[i-1];
        i--;
    }
    A[i] = temp; // Place the element in its correct sorted position.
   

}


  
// Function to partition the array into two sub-arrays
int partition(std::vector<int> & v, int low, int high) {

    
    int pivot = v[high]; // Choose the rightmost element as the pivot
    int i = low - 1; // Index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (v[j] <= pivot) {
            i++;
            std::swap(v[i], v[j]);
        }
    }

    std::swap(v[i + 1], v[high]);//1,-1,2,3,6,10,13,4
    return i + 1; // Return the position of the pivot
}



void quick(std::vector<int>& v, int low, int high){
    if (low < high) {
        // Partition the array into two sub-arrays and get the pivot position
        int pivot = partition(v, low, high);

        // Recursively sort the sub-arrays
        quick(v, low, pivot - 1);
        quick(v, pivot + 1, high);
    }
}





// Merge two sorted subarrays into one sorted subarray
void merge(std::vector<int>& arr, int left, int mid, int right) {


    int n1 = mid - left + 1;//4
    int n2 = right - mid;//4

    // Create temporary arrays
    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    // Copy data to temporary arrays leftArr[] and rightArr[]
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    // Merge the two sorted arrays back into arr[left..right]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr[], if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr[], if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}



// Recursive function to perform merge sort on a vector
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        // Same as (left + right) / 2, but avoids overflow for large left and right
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}



int main(){

    std::vector<int> v = {1,-1,4,2,10,13,6,3};

    sel_sort(v);


    in_sort(v,v.size());
    std::cout<< "Insertion Sort = ";
    for(auto x : v){
        std::cout<< x << " ";
    }

    std::cout<<std::endl;



    quick(v, 0, v.size()-1);

    std::cout<< "Quick Sort = ";
    for(auto x : v){
        std::cout<< x << " ";
    }

    std::cout<<std::endl;



    mergeSort(v,0,v.size()-1);

    std::cout<< "Merge Sort = ";
    for(auto x : v){
        std::cout<< x << " ";
    }

    std::cout<<std::endl;
    
    return 0;
}