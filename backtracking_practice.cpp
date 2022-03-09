#include "bits/stdc++.h"
using namespace std;



void Print(int n) {
	//lastly base condition-> upto which u want to print
	if (n == 1){
		cout << n << ' ';
		return;
	}

				 // Print(n)  should print 1 to n, right ?
    Print(n-1);    // or print(n-1) and then print n
    cout << n << ' '; 
}

vector<int> insert_recusively(vector<int>&arr, int x) {
	if (arr.empty() || arr.back() <= x) {
		arr.push_back(x);
		return arr;
	}

	// if (!arr.empty() && arr.back() > x) {
		int last = arr.back();
		arr.pop_back();
		auto brr = insert_recusively(arr, x);
		brr.push_back(last);
		return brr;
	// }
}

int fact(int n) {
	if (n == 1) {
		return 1;
	}
	return fact(n-1) * n;
}

int main(void){
     ios::sync_with_stdio(0); cin.tie(0);
     
    vector<int> v{1, 2, 3, 4};
    auto k = insert_recusively(v, 0);

    for (auto i : k)
    	cout << i << ' ';

#ifndef ONLINE_JUDGE
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}