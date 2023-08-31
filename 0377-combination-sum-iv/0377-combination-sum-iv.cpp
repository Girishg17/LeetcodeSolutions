class Solution {
public:
    int solve(vector<int>&arr,int t,int i,vector<int>&dp){
       
        if(t==0){
            return 1;
        }
        if(dp[t]!=-1)return dp[t];
      
        int take=0;
        for(int j=0;j<arr.size();j++){
            // if(j>i&&arr[j]==arr[j-1])continue;
            // if(arr[j]>t)break;
            if(arr[j]<=t){
                take=take+solve(arr,t-arr[j],i+1,dp);
            }
        }
        return dp[t]=take;
    }
 
    int combinationSum4(vector<int>& c, int a) {
        vector<int>dp(a+1,-1);
     return solve(c,a,0,dp);
    }
};