class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        int sell = 1;
        int maxProfit = 0;
        int n = prices.size();

        while(sell < n) {
            maxProfit = max(maxProfit, prices[sell] - prices[buy]);
            if(prices[buy] > prices[sell]) {
                buy = sell;
                sell++;
            } else {
                sell++;
            }
        }

        return maxProfit;
    }
};
