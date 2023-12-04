class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
     

        queue<pair<int, pair<int, int>>> q;
        int n = grid.size() - 1;
        int m = grid[0].size() - 1;
        vector<vector<vector<int>>> vis(n + 1, vector<vector<int>>(m + 1, vector<int>(1601, 0)));
        int steps=0;
        q.push({k, {0, 0}});
        int arr[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vis[0][0][k] = 1;
        while (!q.empty()) {
            int size=q.size();
            while(size--){
            int row = q.front().second.first;
            int col = q.front().second.second;
            int w = q.front().first;
            q.pop();

            if (row == n && m == col) return steps;
            for (auto &it : arr) {
                int newrow = row + it[0];
                int newcol = col + it[1];
                if (newrow >= 0 && newcol >= 0 && newrow <= n && newcol <= m && vis[newrow][newcol][w] == 0 &&
                    grid[newrow][newcol] == 0) {
                    q.push({w, {newrow, newcol}});
                   
                    vis[newrow][newcol][w] = 1;
                } else if (newrow >= 0 && newcol >= 0 && newrow <= n && newcol <= m && w > 0 &&
                           vis[newrow][newcol][w - 1] == 0 && grid[newrow][newcol] == 1) {
                    
                    q.push({w-1, {newrow, newcol}});
                   
                    vis[newrow][newcol][w-1] = 1;
                }
            }
        }
        steps++;
        }
        return -1;
    }
};
