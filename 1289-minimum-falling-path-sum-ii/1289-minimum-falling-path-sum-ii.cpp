class Solution {
public:
  
    int solve(vector<vector<int>>&grid,int row,int col,vector<vector<int>>&dp){
        if(row==grid.size()-1)return grid[row][col];
        if(dp[row][col]!=INT_MAX)return dp[row][col];
        int ans=1e8;
        for(int i=0;i<grid[0].size();i++){
           if(i==col)continue;
           ans=min(ans,grid[row][col]+solve(grid,row+1,i,dp));
        }
        return dp[row][col]=ans;
        

    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        int ans=INT_MAX;
         for(int i=0;i<grid[0].size();i++){
             ans=min(ans,solve(grid,0,i,dp));
         }

         return ans;
        
    }
};