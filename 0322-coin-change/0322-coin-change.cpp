class Solution
{
    public:
        int recursion(int n, int t, vector<int> &arr, vector<vector<int>> &dp)
        {

            if (n == 0)
            {
                if (t % arr[n] == 0)
                {
                    return t / arr[n];
                }
                else
                {
                    return 1e9;
                }
            }
            if (dp[n][t] != -1) {return dp[n][t];}
            int nottake = recursion(n - 1, t, arr, dp);
            int take = INT_MAX;
            if (arr[n] <= t) take = 1 + recursion(n, t - arr[n], arr, dp);
            return dp[n][t] = min(take, nottake);
        }

    int coinChange(vector<int> &c, int a)
    {

        vector<vector<int>> dp(c.size(), vector<int> (a+1, -1));
        int ans = recursion(c.size() - 1, a, c, dp);
        if (ans >= 1e9) return -1;
        return ans;
        // vector<int>arr(a+1,INT_MAX);
        // arr[0]=0;
        // for(int i=1;i<a+1;i++){
        //     for(int j=0;j<c.size();j++){
        //         if(i-c[j]>=0 && arr[i-c[j]]!=INT_MAX){
        //             arr[i]=min(arr[i],arr[i-c[j]]+1);
        //         }
        //     }
        // }
        // if(arr.back()==INT_MAX)return -1;
        // return arr.back();


    }
};