//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
     int solve(int N, int W ,int val[],int wt[],int i, int weight,vector<vector<int>> & dp){
        if(i>=N)return 0;
        if(dp[i][weight]!=-1)return dp[i][weight];
        
        
        int take=0;
        if(weight+wt[i]<=W){
            take=val[i]+solve(N,W,val,wt,i,weight+wt[i],dp);
        }
        int dontake=solve(N,W,val,wt,i+1,weight,dp);
        return dp[i][weight]=max(take,dontake);
        
        
    }
  
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(N+1,vector<int>(W+1,-1));
       return solve(N,W,val,wt,0,0,dp);
 
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends