class Solution {
public:
    void solve(int m,int n,int i, int j,vector<vector<char>>& grid){
        if(i<0 || j<0 || i>=m ||j>=n|| grid[i][j]=='0' || grid[i][j]=='2')return;
        grid[i][j]='2';
        int arr[4][4]={{0,1},{1,0},{-1,0},{0,-1}};
        for(auto &it:arr){
            int new_row=it[0]+i;
            int new_col=it[1]+j;
            solve(m,n,new_row,new_col,grid);
        }
        return;

    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++)
        {
     
            for(int j=0;j<n;j++){
 
                if(grid[i][j]=='1'){

                    solve(m,n,i,j,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};