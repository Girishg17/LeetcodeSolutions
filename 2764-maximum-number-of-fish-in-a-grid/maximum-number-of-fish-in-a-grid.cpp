class Solution {
public:
    int solve(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j,
              int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n||vis[i][j] == 1 || grid[i][j] <= 0)
            return 0;
        int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        int total = 0;
        vis[i][j]=1;
        for (auto it : dir) {
            int newrow = it[0] + i;
            int newcol = it[1] + j;
            if (newrow >= 0 && newcol >= 0 && newrow < m && newcol < n &&
                vis[newrow][newcol] == 0 && grid[newrow][newcol] > 0) {
                total =total+ 
                                       solve(grid, vis, newrow, newcol, m, n);
            }
        }
        return total+grid[i][j];
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 0 && grid[i][j] > 0) {
                    ans = max(ans, solve(grid, vis, i, j, m, n));
                }
            }
        }
        return ans;
    }
};