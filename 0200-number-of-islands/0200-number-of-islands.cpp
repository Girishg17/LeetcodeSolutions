class Solution {
public:

    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1'&&vis[i][j]==0){
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    while(!q.empty()){
                        int row=q.front().first;
                        int col=q.front().second;
                        q.pop();
                        for(auto &it:dir){
                            int newRow=row+it[0];
                            int newCol=col+it[1];
                            if(newRow>=0&&newRow<grid.size() &&newCol>=0&&newCol<grid[0].size()&&vis[newRow][newCol]==0&&grid[newRow][newCol]=='1'){
                                q.push({newRow,newCol});
                                vis[newRow][newCol]=1;

                                

                            }
                        }

                    }
                    count++;
                }
            }
        }
        return count;
        
    }
};