class Solution {
public:
    int solve(int m,int n,int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i<0 || j<0 || i>=m || j>=n )return INT_MAX;
        if(i==m-1 && j==n-1)return grid[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=grid[i][j]+min(solve(m,n,i,j+1,grid,dp),solve(m,n,i+1,j,grid,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m,n,0,0,grid,dp);
    }
};