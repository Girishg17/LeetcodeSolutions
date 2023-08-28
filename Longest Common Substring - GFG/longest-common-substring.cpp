//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
   int solve(string &S1, string &S2, int n, int m, int i, int j, int brought,vector<vector<vector<int>>>&dp) {
    if (i >= n || j >= m) {
        return 0;
    }
    if(dp[i][j][brought]!=-1)return dp[i][j][brought];

    if (brought == 1) {
        if (S1[i] == S2[j]) {
            return dp[i][j][brought]= 1 + solve(S1, S2, n, m, i + 1, j + 1, 1,dp);
        } else {
            return 0;
        }
    }

    int take = 0;
    if (S1[i] == S2[j]) {
        take = 1 + solve(S1, S2, n, m, i + 1, j + 1, 1,dp);
    }

    int dontake = max(solve(S1, S2, n, m, i + 1, j, 0,dp), solve(S1, S2, n, m, i, j + 1, 0,dp));

    return dp[i][j][brought]=max(take, dontake);
}

int longestCommonSubstr(string S1, string S2, int n, int m) {
   vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(2, -1)));


    return solve(S1, S2, n, m, 0, 0, 0,dp);
}

};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends