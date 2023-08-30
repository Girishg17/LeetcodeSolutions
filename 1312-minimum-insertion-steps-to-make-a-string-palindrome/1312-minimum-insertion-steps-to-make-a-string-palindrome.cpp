class Solution {
public:
     int solve(string &s,string &temp,int i,int j,vector<vector<int>>&dp){
        if(i>=s.size()||j>=temp.size()){
            return 0;
        }
       if(dp[i][j]!=-1)return dp[i][j];

        int take=0;
        if(s[i]==temp[j]){
            take=1+solve(s,temp,i+1,j+1,dp);
        }
        int notaken=max(solve(s,temp,i+1,j,dp),solve(s,temp,i,j+1,dp));
        return dp[i][j]=max(take,notaken);

    }
    int minInsertions(string s) {
         string temp=s;
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
        reverse(s.begin(),s.end());
        return s.size()-solve(s,temp,0,0,dp);
        
    }
};