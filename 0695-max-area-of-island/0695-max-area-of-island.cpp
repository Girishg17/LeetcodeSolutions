class Solution {
public:
    int dfs(vector<vector<int>>&grid,vector<vector<int>>&vis,int row,int col){
        vis[row][col]=1;
        int dir[][2]={{1,0},{0,1},{-1,0},{0,-1}};
        int count=1;
        for(auto &it:dir){
            int newrow=it[0]+row;
            int newcol=it[1]+col;
            if(newrow>=0 && newrow<grid.size() && newcol>=0 && newcol<grid[0].size() && vis[newrow][newcol]==0 && grid[newrow][newcol]==1){
                
               count+= dfs(grid,vis,newrow,newcol);
            }
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi=0;
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(vis[i][j]==0&&grid[i][j]==1){
                    maxi=max(maxi,dfs(grid,vis, i,j));
                }
            }

        }
        return maxi;
        
    }
};