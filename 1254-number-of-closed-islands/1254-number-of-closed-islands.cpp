class Solution {
public:
  void bfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int row,int col,bool &flag){
        
        if(row==grid.size()-1||row==0||col==grid[0].size()-1||col==0){
            flag=false;

        }
        vis[row][col]=1;
         int di[]={+1,0,-1,0};
        int dj[]={0,+1,0,-1};
       for(int k=0;k<4;k++){
                            int newRow=row+di[k];
                            int newCol=col+dj[k];
                            if(newRow>=0&&newRow<grid.size() &&newCol>=0&&newCol<grid[0].size()&&vis[newRow][newCol]==0&&grid[newRow][newCol]==0){
                               
                               bfs(grid,vis,newRow,newCol,flag);

                                

                            }
                        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
      if(grid.size()==1)return 0;
      int c=0;
      for(int i=0;i<grid.size();i++){
          for(int j=0;j<grid[0].size();j++){
              if(grid[i][j]==0&&vis[i][j]==0){
                  bool flag=true;
                  bfs(grid,vis,i,j,flag);
                  if(flag)c++;

              }
          }
      }
      return c;
        
    }
};