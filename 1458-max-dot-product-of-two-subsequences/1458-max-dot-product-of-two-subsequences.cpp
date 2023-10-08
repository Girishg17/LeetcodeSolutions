class Solution {
public:
    int solve(vector<int>&nums1,vector<int>&nums2,int i,int j,int flag,vector<vector<vector<int>>>&dp){
        if(i>=nums1.size() || j>= nums2.size()){
            if(flag)return 0;
            return INT_MIN;
        }
        if(dp[i][j][flag]!=-1)return dp[i][j][flag];

        int ans1=nums1[i]*nums2[j]+solve(nums1,nums2,i+1,j+1,1,dp);
        int ans2=solve(nums1,nums2,i+1,j+1,flag,dp);
        int ans3=solve(nums1,nums2,i,j+1,flag,dp);
        int ans4=solve(nums1,nums2,i+1,j,flag,dp);
        int maxi=max(ans1,ans2);
        int maxi2=max(ans3,ans4);
        return dp[i][j][flag]=max(maxi,maxi2);
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int flag=0;
        vector<vector<vector<int>>>dp(nums1.size(),vector<vector<int>>(nums2.size(),vector<int>(2,-1)));
        return solve(nums1,nums2,0,0,flag,dp);
        
    }
};