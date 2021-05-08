#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
using namespace std;
 
// First subarray is arr[low..mid]
// Second subarray is arr[mid+1..high]
void merge(long arr[], long low, long mid, long high)
{
    long l1 = mid - low + 1;
    long l2 = high - mid;
 
    long left[l1], right[l2];
 
    for (long i = 0; i < l1; i++) {
        left[i] = arr[low + i];
    }
    for (long i = 0; i < l2; i++) {
        right[i] = arr[mid + 1 + i];
    }
 
    long i = 0, j = 0, k = low;
    while (i < l1 && j < l2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
 
    while (i < l1) {
        arr[k] = left[i];
        i++, k++;
    }
 
    while (j < l2) {
        arr[k] = right[j];
        j++, k++;
    }
}
 
 
void mergeSort(long arr[], long low, long high) {
    if (low < high) {
        //calculate mid-point
        int mid = (low + high) / 2;
 
        // Sort sub-arrays
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
 
        //merge sorted sub-arrays
        merge(arr, low, mid, high);
    }
}
 
 
// Driver code
int main()
{   
    long t;
    cin>>t;
    for(long j=0;j<t;j++){
        long n;
        cin >> n;
        long arr1[n];
        long arr2[n];
        for (long i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (long i = 0; i < n; i++) {
            cin >> arr2[i];
        }
        mergeSort(arr1, 0, n - 1);
        mergeSort(arr2, 0, n - 1);
        long sum=0;
        for (long i = 0; i < n; i++){
            if(arr1[i]<arr2[i])
                sum+=arr1[i];
            else
                sum+=arr2[i];
        }
        cout<<sum<<"\n";
    }
    return 0;
}