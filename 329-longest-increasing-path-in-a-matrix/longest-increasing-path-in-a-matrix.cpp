class Solution {
public:
    int bfs(vector<vector<int>>& dp, int row, int col,
            vector<vector<int>>& mat) {
        if (row >= mat.size() || row < 0 || col >= mat[0].size() || col < 0)
            return 0;
        if (dp[row][col] != -1)
            return dp[row][col];
        //   vis[row][col]=1;
        int dir[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int mx = 0;
        for (auto& it : dir) {

            int newrow = row + it[0];
            int newcol = col + it[1];

            if (newrow < mat.size() && newrow >= 0 && newcol < mat[0].size() &&
                newcol >= 0 && mat[newrow][newcol] > mat[row][col]) {

                mx = max(mx, bfs(dp, newrow, newcol, mat));
            }
        }
         return dp[row][col] = mx + 1;
    }
   

 int longestIncreasingPath(vector<vector<int>>& matrix) {
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
    //  vector<vector<int>>vis(matrix.size(),vector<int>(matrix[0].size(),-1));
    int ans = 0;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {

            ans = max(ans, bfs(dp, i, j, matrix));
        }
    }
    return ans;
}
}
;