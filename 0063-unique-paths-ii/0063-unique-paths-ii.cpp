class Solution {
public:
 int helper(vector<vector<int>>& grid,int row,int col,int &c,vector<vector<int>>& dp){
     if(col>=grid[0].size()||row>=grid.size()||grid[row][col]==1){
         return 0;
     }
     if(col==grid[0].size()-1&&row==grid.size()-1){
        
         return 1;
     }
   
        if(dp[row][col]!=-1)return dp[row][col];
     int side=helper(grid,row,col+1,c,dp);
    int bottom= helper(grid,row+1,col,c,dp);
    return dp[row][col]=side+bottom;
    
 }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
          int c=0;
         vector<vector<int>>dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
        return helper(obstacleGrid,0,0,c,dp);
        
    }
};