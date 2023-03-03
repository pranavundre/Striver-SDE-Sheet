#include <bits/stdc++.h> 
using namespace std;

void insert(stack<int> &s, int x) {
    if (s.empty() || x > s.top()) {
        s.push(x);
        return;
    }
    int temp = s.top();
    s.pop();
    insert(s, x);
    s.push(temp);
}

void sortStack(stack<int> &s) {
    if (s.empty()) return;
    int x = s.top();
    s.pop();
    sortStack(s);
    insert(s, x);
}
