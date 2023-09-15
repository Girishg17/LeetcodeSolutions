class Solution {
public:
    int solve(vector<int>&arr,int n,int i,vector<vector<int>>&dp){
        
        if(i>=arr.size())return 10009;
        if(n==0)return 1;
        if(dp[i][n]!=-1)return dp[i][n];
        int take=INT_MAX;
        if(arr[i]<=n){
            take=1+solve(arr,n-arr[i],i,dp);
        }
        int dontake =solve(arr,n,i+1,dp);
        return dp[i][n]=min(take,dontake);
    }
    int numSquares(int n) {
        vector<int>arr;
        
        for(int i=1;i*i<=n;i++){
            arr.push_back(i*i);
        }
        vector<vector<int>>dp(arr.size()+1,vector<int>(n+1,-1));
       return solve(arr,n,0,dp)-1;
        
    }
};