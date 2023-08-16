class Solution {
public:
    int profit(vector<int>& p, int buynt, int i,vector<vector<int>>&dp) {
        if (i >= p.size()) return 0;
        if(dp[i][buynt]!=-1)return dp[i][buynt];
        int profits = 0;
        
        if (buynt == 1) {
            profits = max(-p[i] + profit(p, 0, i + 1,dp), profit(p, 1, i + 1,dp));
        } else if (buynt == 0) {
            profits = max(p[i] + profit(p, 1, i + 2,dp), profit(p, 0, i + 1,dp));
        } 
        
        return dp[i][buynt]=profits;
    }
    
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return profit(prices, 1, 0,dp); // Start from index 0 with buynt = 0
    }
};
