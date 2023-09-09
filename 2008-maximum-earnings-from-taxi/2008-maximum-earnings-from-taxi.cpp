class Solution {
public:
   static bool cmpare(vector<int>& i1, vector<int>& i2) {
       return i1[0] < i2[0];
   }

   int getNextCurr(vector<vector<int>>& rides,int start,int key){
        int end=rides.size()-1;
        int nextCurr=rides.size();
        while(start<=end){
            int mid=(start+end)/2;
            if(rides[mid][0]>=key){
                nextCurr=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return nextCurr;

    }
     long long solve(vector<vector<int>>& pq, int i, vector<long long>& dp) {
        if (i >= pq.size()) return 0;
     
        if (dp[i] != -1) return dp[i];

       int nextindex=getNextCurr(pq,i,pq[i][1]);

     long long take = pq[i][1]-pq[i][0]+pq[i][2] + solve(pq, nextindex,  dp);
        long long dontake = solve(pq, i + 1,  dp);
        return dp[i]= max(take, dontake);
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end(), cmpare);
        vector<long long> dp(rides.size(), -1);
     
        return solve(rides, 0, dp);
       

        return 0; // Placeholder return value.
    }
};
