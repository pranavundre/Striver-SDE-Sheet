vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int> ret(A.size(), -1);
    stack<int> stk;
    int i = -1;
    while(++i < A.size())
        if(stk.empty()) stk.push(A[i]);
        else
            if(A[i] > stk.top()){
                ret[i] = stk.top();
                stk.push(A[i]);
            }
            else{
                while(!stk.empty() && stk.top() >= A[i]) stk.pop();
                ret[i] = stk.empty() ? -1:stk.top();
                stk.push(A[i]);
            }
    return ret;
}
