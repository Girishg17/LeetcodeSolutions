//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int solve(string &temp,string &s,int i,int j,vector<vector<int>>&dp){
        if(i>=s.size() || j>=s.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int take=0;
        if(temp[i]==s[j]){
            take=1+solve(temp,s,i+1,j+1,dp);
        }
        int dontake=max(solve(temp,s,i,j+1,dp),solve(temp,s,i+1,j,dp));
        return dp[i][j]=max(take,dontake);
    }
    int minimumNumberOfDeletions(string S) { 
        string temp=S;
        reverse(S.begin(),S.end());
        vector<vector<int>>dp(S.size(),vector<int>(S.size(),-1));
       
        return temp.size()- solve(temp,S,0,0,dp);
        // code here
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends