#include <vector>
#include <iostream>
#include <climits>
using namespace std;

class Solution
{
    public:

        int shortestPathBinaryMatrix(vector<vector < int>> &grid)
        {
            if (grid.empty() || grid[0].empty() || grid[0][0] == 1)
            {
                return -1;
            }

            int n = grid.size();
            vector<vector < int>> vis(n, vector<int> (n, 0));
            vector<vector < int>> dp(n, vector<int> (n, 0));
            dp[0][0] = 1;
            queue<pair<int, int>> q;
            q.push({ 0,
                0 });
            vector<vector < int>> dir = {
		{ 0,
                    1 },
                { 1,
                    1 },
                { 1,
                    0 },
                { -1,
                    -1 },
                { 0,
                    -1 },
                { -1,
                    0 },
                { 1,
                    -1 },
                { -1,
                    1 }
            };
            vis[0][0]=1;
            while (!q.empty())
            {
                int row = q.front().first;
                int col = q.front().second;
                
                q.pop();
                if (row == n - 1 && col == n - 1) return dp[row][col];
                for (auto &it: dir)
                {
                    int newRow=row + it[0];
                int newCol=col+it[1];
                    if (newRow < n && newRow >= 0 && newCol < n &&newCol >= 0 && grid[newRow][newCol] == 0&&vis[newRow][newCol]==0 )
                    {
                        q.push({ newRow,
                            newCol });
                        dp[newRow][newCol] = dp[row][col] + 1;
                        vis[newRow][newCol]=1;
                    }
                }
            }
            return -1;
        }
};