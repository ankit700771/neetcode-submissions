class Solution {
public:

    int calulateProfit(vector<int>&price, int index ,int canBuy, int size, vector<vector<int>>& dp) {
        int profit = 0;
        
        if(index >= size) return 0; 

        if(dp[index][canBuy] != -1) {
            return dp[index][canBuy];
        }

        if(canBuy) {
            profit = max(-price[index] + calulateProfit(price, index+1, 0, size, dp), 0 + calulateProfit(price, index+1, 1, size, dp)); 
        } else {
            profit = max(price[index] + calulateProfit(price, index+1, 1, size, dp), 0 + calulateProfit(price, index+1, 0, size, dp));
        }

        dp[index][canBuy] = profit;

        return profit;

    }

    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        vector<vector<int>> dp(size, vector<int>(2, -1));
        int result = calulateProfit(prices, 0, 1, size, dp);
        return result;
    }
};