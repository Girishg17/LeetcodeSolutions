class Solution {
public:
     int recursion(int n, int t, vector<int> &arr, vector<vector<int>> &dp)
        {

            if (n == 0)
            {
                if (t % arr[n] == 0)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            if(dp[n][t]!=-1)return dp[n][t];
            
            int nottake = recursion(n - 1, t, arr, dp);
            int take = 0;
            if (arr[n] <= t) take =  recursion(n, t - arr[n], arr, dp);
            return dp[n][t]=take+nottake;
        }

    int change(int a, vector<int>& c) {
       vector<vector<int>> dp(c.size(), vector<int> (a+1, -1));
       return recursion(c.size() - 1, a, c, dp);
        
    }
};