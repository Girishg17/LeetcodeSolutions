//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int solve(int coins[],int N,int sum,int i,vector<vector<long long int>>&dp){
        if(i>=N)return 0;
        if(sum<0)return 0;
        if(dp[i][sum]!=-1){return dp[i][sum];}
        if(sum==0){
            return 1;
        }
        
        if(i==N-1){
            if(sum%coins[i]==0)return 1;
            return 0;
        }
        
        long long int take=0;
      
        if(coins[i]<=sum){
            take=solve(coins,N,sum-coins[i],i,dp);
            
        }
        long long int dontake=solve(coins,N,sum,i+1,dp);
        return dp[i][sum]=take+dontake;
    }
    long long int count(int coins[], int N, int sum) {
        vector<vector<long long int>>dp(N,vector<long long int>(sum+1,-1));
        // code here.
        return solve(coins,N,sum,0,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends