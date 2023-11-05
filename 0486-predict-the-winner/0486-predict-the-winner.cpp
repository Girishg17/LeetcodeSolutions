class Solution {
public:
    int solve(vector<int>&nums,int i,int j,vector<vector<int>>&dp){
        if(i==j)return nums[i];
        if(dp[i][j]!=-1)return dp[i][j];
        int chance1=nums[i]-solve(nums,i+1,j,dp);
        int chance2=nums[j]-solve(nums,i,j-1,dp);
        return dp[i][j]= max(chance1,chance2);
        
        
      
    return 0;
    }
    bool predictTheWinner(vector<int>& nums) {
    
     int i=0;
     int j=nums.size()-1;
     vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
   return solve(nums,i,j,dp)>=0;
   

    }
};