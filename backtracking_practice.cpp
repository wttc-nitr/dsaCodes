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

int fact(int n) {
	if (n == 1) {
		return 1;
	}
	return fact(n-1) * n;
}

int main(void){
     ios::sync_with_stdio(0); cin.tie(0);
     
    cout << fact(4);

#ifndef ONLINE_JUDGE
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}