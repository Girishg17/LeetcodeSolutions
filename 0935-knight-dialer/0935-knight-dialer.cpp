class Solution {
public:
    # define mode 1000000007
    long long solve(int n, int x, int y, vector<vector<vector<int>>>& dp) {
        if (n == 0) return 1;
        if (dp[x][y][n] != -1) return dp[x][y][n];
        int dir[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {-1, 2}, {1, 2}, {-1, -2}, {1, -2}};
        long long ans = 0;
        for (auto it : dir) {
            int newrow = x + it[0];
            int newcol = y + it[1];
            if ((newrow == 3 && newcol == 0) || (newrow == 3 && newcol == 2) || newrow < 0 || newrow > 3 || newcol < 0 || newcol > 2) continue;
            ans = (ans + solve(n - 1, newrow, newcol, dp))%mode ;
        }
        return dp[x][y][n] = ans;
    }

    int knightDialer(int n) {
        int ans = 0;
        vector<vector<vector<int>>> dp(4, vector<vector<int>>(3, vector<int>(n + 1, -1))); // Increase size by 1 for n
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if ((i == 3 && j == 0) || (i == 3 && j == 2)) continue;
                ans = (ans + solve(n-1, i, j, dp)) % mode;
            }
        }
        return ans;
    }
};
