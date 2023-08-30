//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
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
    int countMin(string str){
    //complete the function here
    string temp=str;
        vector<vector<int>>dp(str.size()+1,vector<int>(str.size()+1,-1));
        reverse(str.begin(),str.end());
        return str.size()-solve(str,temp,0,0,dp);
    
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends