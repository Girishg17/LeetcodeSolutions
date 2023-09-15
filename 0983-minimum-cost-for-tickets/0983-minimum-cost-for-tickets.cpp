class Solution {
public:
    int solve(vector<int>&days,vector<int>&costs,int i,vector<int>&dp){
        if(i>=days.size())return 0;
    if(dp[i]!=-1)return dp[i];
        int res=2e9;
        int cur=days[i];
        res=min(res,costs[2]+solve(days,costs,upper_bound(days.begin(),days.end(),cur+30-1)-days.begin(),dp));
        res=min(res,costs[1]+solve(days,costs,upper_bound(days.begin(),days.end(),cur+7-1)-days.begin(),dp));
        res=min(res,costs[0]+solve(days,costs,i+1,dp));
        return dp[i]=res;
        

    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size(),-1);
        return solve(days,costs,0,dp);
        





        
    }
};