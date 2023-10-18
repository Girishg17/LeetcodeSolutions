class Solution {
public:
   int dfs(vector<vector<int>>&adj,vector<int>&time,int node,vector<int>&dp){
      if(dp[node]!=-1)return dp[node];
       int take=0;
       for(auto it:adj[node]){
       take=max(take,dfs(adj,time,it,dp));
       }
       return dp[node]= take+time[node-1];
   }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
      vector<vector<int>>adj(n+1);
      vector<int>dp(n+1,-1);
     
     
      for(int i=0;i<relations.size();i++){
          adj[relations[i][0]].push_back(relations[i][1]);
      }
      int ans=0;
      for(int i=1;i<=n;i++){
          ans=max(ans,dfs(adj,time,i,dp));

      }
      return ans;
   
    }
};