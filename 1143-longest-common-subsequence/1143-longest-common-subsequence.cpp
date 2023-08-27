class Solution {
public:
    int solve(string &s1, string &s2, int n, int m, int i, int j, vector<vector<int>>& dp) {
        if (i >= n || j >= m) {
            return 0;
        }
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        if (s1[i] == s2[j]) {
            return dp[i][j] = 1 + solve(s1, s2, n, m, i + 1, j + 1, dp);
        }
        
        int option1 = solve(s1, s2, n, m, i + 1, j, dp);
        int option2 = solve(s1, s2, n, m, i, j + 1, dp);
        
        return dp[i][j] = max(option1, option2);
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(text1, text2, n, m, 0, 0, dp);
    }
};
