class Solution {
public:
    int solve(string &s,int i,vector<int>&dp){
        if(i>=s.size())return 1;
        if(s[i]=='0')return 0;
        if(dp[i]!=-1)return dp[i];
        int take1=0;
        int take2=0;
        if( s[i]!='0'){
            take1=solve(s,i+1,dp);
        }
        if(i+1<s.size() ){
            string sub=s.substr(i,2);
            int t=stoi(sub);
            if(t>0 && t<=26){
                take2=solve(s,i+2,dp);
            }
        }
        return dp[i]=take1+take2;
        
        
    }
    int numDecodings(string s) {
        vector<int>dp(s.size(),-1);
        return solve(s,0,dp);
        
    }
};