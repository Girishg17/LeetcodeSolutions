class Solution {
public:
       int recursion(vector<int>& prices,int i,int buy,int cnt,vector<vector<vector<int>>>&dp,int k){
        if(i>=
        prices.size()||cnt
        >=k)return 0;
        if(dp[i][buy][cnt]!=-1)return dp[i][buy][cnt];

       int profit=0;
        if(buy){
          profit= max(-prices[i]+recursion(prices,i+1,0,cnt,dp,k),recursion(prices,i+1,1,cnt,dp,k));

        }
        else{
            profit=max(prices[i]+recursion(prices,i+1,1,cnt+1,dp,k),recursion(prices,i+1,0,cnt,dp,k));
        }
        return dp[i][buy][cnt] =profit;
    }
    int maxProfit(int k, vector<int>& prices) {
         vector<vector<vector<int> > > dp(prices.size(), vector<vector<int> >(2, vector<int>(k,-1)));
        return recursion(prices,0,1,0,dp,k);
        
    }
};