//贪心策略
//找到相差最大子段，保证买入在卖出之前

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int buy = INT_MAX;
        int sell = INT_MIN;
        int res = 0;
        for(int i = 0; i < prices.size(); ) {
            if(buy > prices[i]) {
                buy = prices[i];
                int j = i + 1;
                while(j < prices.size() && prices[j] >= buy) {
                    res = res > prices[j] - buy ? res : prices[j] - buy;
                    j++;
                }
                i = j;
            }
        }
        return res;
    }
};