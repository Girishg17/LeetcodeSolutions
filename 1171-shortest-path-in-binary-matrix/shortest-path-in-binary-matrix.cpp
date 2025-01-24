class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1)return -1;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> st;
        int dir[8][8] = {{0, 1}, {1, 0},   {0, -1}, {-1, 0},
                         {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
       st.push({0,0});
       vis[0][0]=1;
       int ans=1;
       while(!st.empty()){
         int size=st.size();
         while(size--){
            int row=st.front().first;
            int col=st.front().second;
            if(row==n-1 && col==m-1)return ans;
           
            st.pop();
            for(auto it:dir){
                int newrow=row+it[0];
                int newcol=col+it[1];
                if(newrow>=0 && newcol>=0 && newrow<n && newcol<m && vis[newrow][newcol]==0 && grid[newrow][newcol]==0){
                    st.push({newrow,newcol});
                    vis[newrow][newcol]=1;
                }
            }
         }
         ans++;
       }
       return -1;
    }
};