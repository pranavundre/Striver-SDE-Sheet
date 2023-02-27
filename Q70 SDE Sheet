class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i: nums){
            if(k-- > 0){
                pq.push(i);
                continue;
            }
            if(i >= pq.top()) {
                pq.pop();
                pq.push(i);
            }
        }
        return pq.top();
    }
};
