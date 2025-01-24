class Solution {
public:
    void solve(vector<vector<char>>& grid,int r,int c,int m,int n){
        if(r<0 || c <0 || r>=m || c>=n)return;
        int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
        grid[r][c]='0';
        for(auto it:dir){
                int newrow=r+it[0];
                int newcol=c+it[1];
                if(newrow >=0 && newcol>=0 && newrow<m && newcol<n && grid[newrow][newcol]=='1'){
                    solve(grid,newrow,newcol,m,n);
                }

        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    solve(grid,i,j,m,n);
                }

            }
        }
        return ans;
    }
};