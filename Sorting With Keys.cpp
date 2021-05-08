#include <bits/stdc++.h>
using namespace std;
//Count inversions in sorting as per values after sorting the array on keys
//merge code for merge sort calling
int merge(int arr[], int start, int mid, int end) {
	int invCount = 0;
	int temp[end - start + 1];
	int p = start, q = mid + 1;
	int k = 0;
	for (int i = start; i <= end; i++) {
		if (p > mid)temp[k++] = arr[q++];
		else if (q > end)temp[k++] = arr[p++];
		else if (arr[p] <= arr[q]) {temp[k++] = arr[p++];
		}
		else {invCount += (mid - p + 1);temp[k++] = arr[q++];
		}
	}
	for (int i = 0; i < k; i++)
		arr[start++] = temp[i];
	return invCount;
}

//merge sort driver code
int merge_sort(int arr[], int start, int end) {
	int invCount = 0;
	if (start < end) {
		int mid = start + (end - start) / 2;
		invCount += merge_sort(arr, start, mid);
		invCount += merge_sort(arr, mid + 1, end);
		invCount += merge(arr, start, mid, end);
	}
	return invCount;
}

//return comparison between values of 2 pairs
bool cmp(const pair<int, int> p1, const pair<int, int> p2) {
	return p1.second < p2.second;
}


int main(){
	//driver code
	int n;
	cin >> n;
	pair<int, int>arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i].first;
	for (int i = 0; i < n; i++)
		cin >> arr[i].second;sort(arr, arr + n, cmp);
	int arr2[n];
	for (int i = 0; i < n; i++)
		arr2[i] = arr[i].first;
	int ans = merge_sort(arr2, 0, n - 1);
	cout << ans;
}