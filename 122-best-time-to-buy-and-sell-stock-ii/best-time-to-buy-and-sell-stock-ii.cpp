class Solution {
public:
    int solve(vector<int>& prices,int index,int buy,vector<vector<int>>&dp){
        if(index>=prices.size())return 0;
        if(dp[index][buy]!=-1)return dp[index][buy];
        int buyed=0,sell=0;
        if(buy==0){
            buyed=max(solve(prices,index+1,1,dp)-prices[index],solve(prices,index+1,0,dp));
        }
        else{
        sell=max(prices[index]+solve(prices,index+1,0,dp),solve(prices,index+1,1,dp));
        }
        return dp[index][buy]= max(sell,buyed);
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return solve(prices,0,0,dp);
    }
};