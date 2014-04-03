class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int minval = INT_MAX;
        int maxout = 0;
        
        for (vector<int>::iterator iter = prices.begin(); iter != prices.end(); iter++) {
            int val = *iter;
            if (val<minval)
                minval = val;
            int diff = val-minval;
            if (diff>maxout)
                maxout = diff;
        }
        
        return maxout;
    }
};
