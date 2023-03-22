// An efficient C++ program to find
// maximum of all minimums of
// windows of different sizes
#include <bits/stdc++.h> 
using namespace std;

// void printMaxOfMin(int arr[], int n)
vector<int> maxMinWindow(vector<int> arr, int n)
{
	// Used to find previous and next smaller
	stack<int> s;
    vector<int> mx;

	// Arrays to store previous and next smaller
	int left[n + 1];
	int right[n + 1];

	// Initialize elements of left[] and right[]
	for (int i = 0; i < n; i++) {
		left[i] = -1;
		right[i] = n;
	}

	// Fill elements of left[] using logic discussed on
	// https://www.geeksforgeeks.org/next-greater-element/
	for (int i = 0; i < n; i++) {
		while (!s.empty() && arr[s.top()] >= arr[i])
			s.pop();

		if (!s.empty())
			left[i] = s.top();

		s.push(i);
	}

	// Empty the stack as stack is
	// going to be used for right[]
	while (!s.empty())
		s.pop();

	// Fill elements of right[] using same logic
	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() && arr[s.top()] >= arr[i])
			s.pop();

		if (!s.empty())
			right[i] = s.top();

		s.push(i);
	}

	// Create and initialize answer array
	int ans[n + 1];
	for (int i = 0; i <= n; i++)
		ans[i] = INT_MIN;

	// Fill answer array by comparing minimums of all
	// lengths computed using left[] and right[]
	for (int i = 0; i < n; i++) {
		// length of the interval
		int len = right[i] - left[i] - 1;

		// arr[i] is a possible answer for this length
		// 'len' interval, check if arr[i] is more than
		// max for 'len'
		ans[len] = max(ans[len], arr[i]);
	}

	// Some entries in ans[] may not be filled yet. Fill
	// them by taking values from right side of ans[]
	for (int i = n - 1; i >= 1; i--)
		ans[i] = max(ans[i], ans[i + 1]);

	for (int i = 1; i <= n; i++)
        mx.emplace_back(ans[i]);
        
    return mx;
}


// My code using deque but gives TLE

// #include <bits/stdc++.h> 
// vector<int> maxMinWindow(vector<int> a, int n) {
//     // Write your code here.
//     vector<int> mx;
//     for(int i = 1; i <= n; i++){
//         int mxmin = INT_MIN;
//         deque<int> dq;
//         for(int x = 0; x < n; x++){
//             while(!dq.empty() && a[x]<a[dq.back()]) dq.pop_back();
//             dq.push_back(x);
//             if(dq.back()-dq.front() == i) dq.pop_front();
//             if(x >= i-1) mxmin = max(mxmin, a[dq.front()]);
//         }
//         mx.emplace_back(mxmin);
//     }
//     return mx;
// }
