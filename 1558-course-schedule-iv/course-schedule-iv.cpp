class Solution {
public:
    bool solve(unordered_map<int,vector<int>>&mp,vector<vector<int>>& queries,int v,int curr,vector<vector<int>>&dp){
        if(curr==v) {
            dp[curr][v]=1;
            return true;}
        if(dp[curr][v]!=-1){
            if(dp[curr][v]==0)return false;
            return true;
        }
        for(auto it:mp[curr] ){
            if(solve(mp,queries,v,it,dp)){
                dp[curr][v]=1;
                return true;}
        }
        dp[curr][v]=0;
        return false;

    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<prerequisites.size();i++){
            mp[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<bool>ans(queries.size());
        vector<vector<int>>dp(numCourses,vector<int>(numCourses,-1));
        for(int i=0;i<queries.size();i++){
            int u=queries[i][0];
            int v=queries[i][1];
            for(auto it:mp[u]){
            if(solve(mp,queries,v,it,dp)){
                ans[i]=true;
                break;
            }
            }
        }
        return ans;
        
    }
};