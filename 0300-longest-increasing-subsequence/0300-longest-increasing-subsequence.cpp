class Solution {
public:
//     int recursion(int i,vector<int>&nums,int prev, vector<vector<int>>&dp){
//         if(i>=nums.size())return 0;
//         if(dp[i][prev+1]!=-1)return dp[i][prev+1];
//         int take=0;
//         if(prev==-1||nums[i]>nums[prev]){
//             take=1+recursion(i+1,nums,i,dp);
//         }
//         int notake=recursion(i+1,nums,prev,dp);
//         return dp[i][prev+1]=max(take,notake);
        
//     }
    int lengthOfLIS(vector<int>& nums) {
//         vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
        
//          return   recursion(0,nums,-1,dp);
        
        //optimal
        if(nums.size()==0)return 0;
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[index]=nums[i];
            }
            
        }
        return ans.size();
           
        
        
    }
};