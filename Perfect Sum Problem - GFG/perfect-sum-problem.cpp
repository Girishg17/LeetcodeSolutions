//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    
	public:
	int maxi=1e9+7;
	int solve(int arr[],int n,int sum,int i,vector<vector<int>>&dp){
	 
	 
	   if(sum==0){
	       if(i!=n){
	           if(arr[i]==0){
	           return 1+solve(arr,n,sum,i+1,dp);
	           }
	       }
	       else{
	           return 1;
	       }
	   }
	    if(i==n)return 0;
	   
	   
	   if(dp[i][sum]!=-1)return dp[i][sum];
	   int take=0;
	   if(arr[i]<=sum){
	       take=take+solve(arr,n,sum-arr[i],i+1,dp);
	   }
	   int dontake=solve(arr,n,sum,i+1,dp);
	   return dp[i][sum]= (take+dontake)%(maxi);
	    
	    
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solve(arr,n,sum,0,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends