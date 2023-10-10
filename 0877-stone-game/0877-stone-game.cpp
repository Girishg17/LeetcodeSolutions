class Solution {
public:
   bool solve(vector<int>&piles,int start,int end ,int turn,vector<vector<int>>&dp){
       if(start>end)return 0;
       if(dp[start][end]!=-1)return dp[start][end];
       if(turn){
           int r1=solve(piles,start+1,end,0,dp)+piles[start];
           int r2=solve(piles,start,end-1,0,dp)+piles[end];
           return dp[start][end]=max(r1,r2);
       }
       int r1=solve(piles,start+1,end,1,dp)-piles[start];
        int r2=solve(piles,start,end-1,1,dp)-piles[end];
        return dp[start][end]= max(r1,r2);
   }
    bool stoneGame(vector<int>& piles) {
        int start=0;
        int end=piles.size()-1;
        vector<vector<int>>dp(piles.size(),vector<int>(piles.size(),-1));
        return solve(piles,start,end,1,dp);
        
    }
};