class Solution {
public:
  int dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int row,int col){
      int sum=grid[row][col];
      vis[row][col]=1;
      int dir[][2]={{1,0},{0,1},{-1,0},{0,-1}};
      for(int i=0;i<4;i++){
          int newrow=row+dir[i][0];
          int newcol=col+dir[i][1];
          if(newrow>=0&&newrow<grid.size()&&newcol>=0&&newcol<grid[0].size()&&vis[newrow][newcol]==0&&grid[newrow][newcol]>0){
              sum=sum+dfs(grid,vis,newrow,newcol);
          }
      }
      return sum;
  }
  
    int findMaxFish(vector<vector<int>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        int maxi=INT_MIN;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(vis[i][j]==0&&grid[i][j]>0){
                    maxi=max(maxi,dfs(grid,vis,i,j));

                }
            }
        }
        if(maxi==INT_MIN)return 0;
        return maxi;
        
    }
};