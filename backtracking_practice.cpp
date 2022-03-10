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

vector<int> insert_recusively(vector<int> arr, int x) {
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

// same as above but without returning anything
void Insert_recusively(vector<int> &arr, int x) {
	if (arr.empty() || arr.back() <= x) {
		arr.push_back(x);
		return;
	}

	// if (!arr.empty() && arr.back() > x) {
		int last = arr.back();
		arr.pop_back();
		Insert_recusively(arr, x);			// i should be in upper-case
		arr.push_back(last);
		
	// }
}

void sortRecursively(vector<int> &arr) {
	if (arr.size() <= 1)
		return;

	int last = arr.back();
	arr.pop_back();
	sortRecursively(arr);
	Insert_recusively(arr, last);
}

int fact(int n) {
	if (n == 1) { 
		return 1;
	}
	return fact(n-1) * n;
}

void insertInStack(stack<int> &stk, int x) {
	if (stk.empty() || stk.top() <= x) {
		stk.push(x);
		return;
	}

	// if (stk.top() > x) {
		int last = stk.top();
		stk.pop();
		insertInStack(stk, x);
		stk.push(last);
	// }
}

void sortStack(stack<int> &stk) {
	if (stk.size() <= 1) {	// single element is already sorted
		return;
	}

	int last = stk.top();
	stk.pop();
	sortStack(stk);
	insertInStack(stk, last);
}

void printStack(stack<int> stk) {
	vector<int> arr;

	while (!stk.empty()) {
		arr.push_back(stk.top());
		stk.pop();
	}

	reverse(arr.begin(), arr.end());

	cout << '\n';
	for (auto i : arr)
		cout << i << ' ';
}

int main(void){
     ios::sync_with_stdio(0); cin.tie(0);
     
    stack<int> naya;
    for (int i=100; i >= 1; i--)
    	naya.push(i);

    // for (int i=11; i <= 15; i++)
    // 	naya.push(i);

    printStack(naya);

    sortStack(naya);

    printStack(naya);

#ifndef ONLINE_JUDGE
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}

