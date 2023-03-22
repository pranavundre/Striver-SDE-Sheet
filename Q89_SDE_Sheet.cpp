class StockSpanner {
public:
    stack<pair<int, int>> st;
    int next(int price) {
        if(st.empty()){
            st.push(make_pair(price,1));
            return 1;
        }
        pair<int, int> p = {price, 1};
        while(!st.empty() && st.top().first <= price){
            p.second += st.top().second;
            st.pop();
        }
        st.push(p);
        return st.top().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
