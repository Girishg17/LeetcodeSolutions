class Solution {
public:
    void bfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int row,int col){
        if(row>=grid.size()||row<0||col>=grid[0].size()||col<0||vis[row][col]==1||grid[row][col]==0)return;
        vis[row][col]=1;
        bfs(grid,vis,row+1,col);
        bfs(grid,vis,row,col+1);
        bfs(grid,vis,row-1,col);
        bfs(grid,vis,row,col-1);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        if(grid.size()==1)return 0;
        for(int i=0;i<grid[0].size();i++){
            if(grid[0][i]==1&&vis[0][i]==0){
                bfs(grid,vis,0,i);
            }
            if(grid[grid.size()-1][i]==1&&vis[grid.size()-1][i]==0){
                bfs(grid,vis,grid.size()-1,i);
            }
        }
        for(int i=0;i<grid.size();i++){
            if(grid[i][0]==1&&vis[i][0]==0){
                bfs(grid,vis,i,0);
            }
             if(grid[i][grid[0].size()-1]==1&&vis[i][grid[0].size()-1]==0){
                bfs(grid,vis,i,grid[0].size()-1);
            }
        }
        int count=0;
        for(int i=1;i<grid.size()-1;i++){
            for(int j=1;j<grid[0].size()-1;j++){
                if(grid[i][j]==1&&vis[i][j]==0){
                    count++;
                }
            }
        }
        return count;

          
        
    }
};