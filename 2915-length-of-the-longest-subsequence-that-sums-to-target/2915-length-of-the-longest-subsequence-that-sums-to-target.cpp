class Solution {
public:
    int solve(vector<int>&nums,int target,int i,vector<vector<int>>&dp){
        if(target==0){
           
            return 0;
        }
        if(i>=nums.size()||target<0){
            
            return -1001;
        }
        if(dp[i][target]!=-1)return dp[i][target];
        int take=0;
       
        take=1+solve(nums,target-nums[i],i+1,dp);
        
        int dontake=solve(nums,target,i+1,dp);
        return dp[i][target]=max(take,dontake);
        
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
     

       vector<vector<int>>dp(1001,vector<int>(1001,-1));
      int ans= solve(nums,target,0,dp);
        
        return (ans>0)?ans:-1;

    }
};