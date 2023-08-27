//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int solve(string &s1,string &s2,int n,int m,int i,int j,vector<vector<int>>&dp){
        if(i>=n||j>=m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int c=0;
        int y=0;
        if(s1[i]==s2[j]){
             c=1+solve(s1,s2,n,m,i+1,j+1,dp);
        }
        else{
            y=max(solve(s1,s2,n,m,i+1,j,dp),solve(s1,s2,n,m,i,j+1,dp));
        }
        return dp[i][j]=max(c,y);
    }
    int lcs(int n, int m, string s1, string s2)
    {
        // your code here
        vector<vector<int>>dp(n,vector<int>(m,-1));
       return solve(s1,s2,n,m,0,0,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends