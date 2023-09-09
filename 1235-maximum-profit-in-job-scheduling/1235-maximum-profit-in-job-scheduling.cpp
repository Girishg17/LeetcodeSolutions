class Solution {
public:
    int solve(vector<vector<int>>& pq, int i, vector<int>& dp) {
        if (i >= pq.size()) return 0;
     
        if (dp[i] != -1) return dp[i];

        int nextindex = i + 1;
        while (nextindex < pq.size() && pq[nextindex][0] <pq[i][1]) {
            nextindex++;
        }

     int  take = pq[i][2] + solve(pq, nextindex,  dp);
        int dontake = solve(pq, i + 1,  dp);
        return dp[i]= max(take, dontake);
    }

    int jobScheduling(vector<int>& start, vector<int>& end, vector<int>& profit) {
        vector<int> dp(profit.size(), -1);
        vector<vector<int>> pq(profit.size(),vector<int>(3));
        for (int i = 0; i < profit.size(); i++) {
           pq[i][0]=start[i];
           pq[i][1]=end[i];
           pq[i][2]=profit[i];
        }
        sort(pq.begin(), pq.end());
        return solve(pq, 0, dp);
    }
};
