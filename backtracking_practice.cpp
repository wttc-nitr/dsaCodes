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

void delete_KthElement(stack<int> &stk, int k) {
	// if (stk.size() < k || k == 0)
	// 	return;

	if (k == 0) {
		stk.pop();
		return;
	}

	// if (k != 0) {
		int last = stk.top();
		stk.pop();
		delete_KthElement(stk, k-1);
		stk.push(last);
	// }
}

void bottomInsert(stack<int> &stk, int x) {
	if (stk.empty()) {
		stk.push(x);
		return;
	}

	// if (!stk.empty()) {
		int last = stk.top();
		stk.pop();
		bottomInsert(stk, x);
		stk.push(last);
	// }
}

void reverseStack(stack<int> &stk) {
	if (stk.size() <= 1) {  // 1 sized stack is already reversed in itself
		return;
	}

	int last = stk.top();
	stk.pop();
	reverseStack(stk);
	bottomInsert(stk, last);
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
    for (int i=10; i >= 1; i--)
    	naya.push(i);

    printStack(naya);

    reverseStack(naya);

    printStack(naya);
    

#ifndef ONLINE_JUDGE
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}

