class Solution {
public:
    int solve(vector<int> & nums,int prev,int i,vector<vector<int>>&dp){
        if(i>=nums.size())return 0;
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        int take=0;
        if(prev==-1|| nums[i]>nums[prev]){
            take=1+solve(nums,i,i+1,dp);
        }
        int dontake=solve(nums,prev,i+1,dp);
        return dp[i][prev+1]=max(take,dontake);

    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
        return solve(nums,-1,0,dp);
    }
};