class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int start = 0;
        int end = 0;
        int maxi = 1;

        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
            if (i + 1 < n && s[i] == s[i + 1]) {
                start = i;
                end = i + 1;
                maxi = 2;
                dp[i][i + 1] = 1;
            }
        }

        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len+1; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = 1;
                    if (len > maxi) {
                        maxi = len;
                        start = i;
                        end = j;
                    }
                }
            }
        }

        return s.substr(start, end - start + 1);
    }
};
