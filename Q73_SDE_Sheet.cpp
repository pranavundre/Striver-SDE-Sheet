#include <bits/stdc++.h> 

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k){
    priority_queue<int, vector<int>, greater<int>> minheap;
    vector<int> ret;
    for(int i = 0; i < k; i++)
        for(int j = 0; j < kArrays[i].size(); j++)
            minheap.push(kArrays[i][j]);
            
    while(!minheap.empty()){
        ret.emplace_back(minheap.top());
        minheap.pop();
    }
    return ret;
}
