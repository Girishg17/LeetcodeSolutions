class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1)return -1;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        int dir[8][8] = {{0, 1}, {1, 0},   {0, -1}, {-1, 0},
                         {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
        q.push({0, 0});
        vis[0][0] = 1;
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int row = q.front().first;
                int col = q.front().second;
                if (row == n - 1 && col == m - 1)
                    return steps+1;
                q.pop();
                for (int i = 0; i < 8; i++) {
                    int newrow = row + dir[i][0];
                    int newcol = col + dir[i][1];
                    // if(newrow==n-1 && newcol==m-1)return steps;
                    if (newrow < n && newcol < m && newrow >= 0 &&
                        newcol >= 0 && vis[newrow][newcol] == 0 &&
                        grid[newrow][newcol] == 0) {
                        q.push({newrow, newcol});
                        vis[newrow][newcol] = 1;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};