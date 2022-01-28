/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
*/
#include "bits/stdc++.h"
using namespace std;
#define ll long long

void merge(vector<int> &arr, int lo, int mid, int hi){
    vector<int> temp(hi-lo + 1);
    
    int itr1 = lo, itr2 = mid+1, k = 0;
    
    while (itr1 <= mid && itr2 <= hi){
        if (arr[itr1] <= arr[itr2])
            temp[k++] = arr[itr1++];
        
        else temp[k++] = arr[itr2++];
    }
    
    //copy rest
    while (itr1 <= mid)
        temp[k++] = arr[itr1++];
    
    while (itr2 <= hi)
        temp[k++] = arr[itr2++];
    
    // copy temp to original array, from lo to hi
    for (int i=lo; i <= hi; i++)
        arr[i] = temp[i-lo];
}

void mergeSort(vector<int> &arr, int lo, int hi){
	if (lo == hi)
		return;

	int mid = lo + (hi-lo) / 2;

	//sort left half
	mergeSort(arr, lo, mid);

	//sort right half
	mergeSort(arr, mid+1, hi);

	// merge left half and right half
	merge(arr, lo, mid, hi);
}

int main(void){
     ios::sync_with_stdio(0); cin.tie(0);
    
    vector<int> v{1, 5, 8, 2, 4, 9};

    mergeSort(v, 0, v.size()-1);

    for (auto i : v)
    	cout << i << ' ';
    
    return 0;
}