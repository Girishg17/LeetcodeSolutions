class Solution {
public:
 bool   solve(string &s1,string &s2,string &s3,int i,int j,int k,vector<vector<int>>&dp){
        if(i==s1.size()&&j==s2.size()&&k==s3.size())return true;
       if(dp[i][j]!=-1)return dp[i][j];
        // if(i>=s1.size()||j>=s2.size()||k>=s3.size())return false;
       
        bool flag=false;
        if(i<s1.size()&&s1[i]==s3[k]){
            flag=solve(s1,s2,s3,i+1,j,k+1,dp);
            
        }

        bool flag2=false;
        if(j<s2.size()&&s2[j]==s3[k]){
            flag2=solve(s1,s2,s3,i,j+1,k+1,dp);
            
        }
       
        return dp[i][j]=flag||flag2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        
        if (n1 + n2 != n3) {
            return false;
        }

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
      
      
       return solve(s1,s2,s3,0,0,0,dp);
    }
};