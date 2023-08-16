class Solution {
public:
    int recursion(vector<int>& prices,int fee,int i,int buy,vector<vector<int>>&dp){
        if(i>=prices.size())return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        int profit=0;
        if(buy){
            profit=max(-fee-prices[i]+recursion(prices,fee,i+1,0,dp),recursion(prices,fee,i+1,1,dp));
        }
        else{
            profit=max(prices[i]+recursion(prices,fee,i+1,1,dp),recursion(prices,fee,i+1,0,dp));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
       
        return recursion(prices,fee,0,1,dp);
        
    }
};