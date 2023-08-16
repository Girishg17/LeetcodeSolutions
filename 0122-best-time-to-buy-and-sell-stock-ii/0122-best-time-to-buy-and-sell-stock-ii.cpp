class Solution {
public:
  int recursion(vector<int>&prices,int buy,int i,vector<vector<int>>&dp){
      if(i==prices.size())return 0;
      if(dp[i][buy]!=-1)return dp[i][buy];
      int profit=0;
      if(buy){
          int buy=-prices[i]+recursion(prices,0,i+1,dp);
          int dontbuy=recursion(prices,1,i+1,dp);
          profit=max(buy,dontbuy);
        
      }
      else{
         int sell= prices[i]+recursion(prices,1,i+1,dp);
         int imnot=recursion(prices,0,i+1,dp);
        profit=max(sell,max(imnot,profit));
      }
return dp[i][buy]=profit;
  }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
       return recursion(prices,1,0,dp);
        
    }
};