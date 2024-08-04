class Solution {
public:
    int solve(int row,int col,int m,int n,vector<vector<int>>&dp,vector<vector<int>>& arr)
    {
        if(row>=m || col >=n || row<0 || col <0 || arr[row][col]==1)return 0;
        if(row== m-1 && col == n-1)return 1;
        if(dp[row][col]!=-1)return dp[row][col];
        int right=solve(row,col+1,m,n,dp,arr);
        int down=solve(row+1,col,m,n,dp,arr);
        return dp[row][col]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int i=0;
        int j=0;
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(i,j,m,n,dp,obstacleGrid);
    }
};