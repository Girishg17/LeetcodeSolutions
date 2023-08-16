class Solution {
public:
   int recursion(vector<int>& prices,int i,int buy,int cnt,vector<vector<vector<int>>>&dp){
        if(i>=
        prices.size()||cnt
        >=2)return 0;
        if(dp[i][buy][cnt]!=-1)return dp[i][buy][cnt];

       int profit=0;
        if(buy){
          profit= max(-prices[i]+recursion(prices,i+1,0,cnt,dp),recursion(prices,i+1,1,cnt,dp));

        }
        else{
            profit=max(prices[i]+recursion(prices,i+1,1,cnt+1,dp),recursion(prices,i+1,0,cnt,dp));
        }
        return dp[i][buy][cnt] =profit;
    }
    int maxProfit(vector<int>& prices) {
     vector<vector<vector<int> > > dp(prices.size(), vector<vector<int> >(2, vector<int>(2,-1)));
       return recursion(prices,0,1,0,dp);
        
    }
};