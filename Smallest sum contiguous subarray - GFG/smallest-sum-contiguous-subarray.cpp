//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int smallestSumSubarray(vector<int>& nums){
      //Code here
      int ans=INT_MIN;
      int maxi=0;
      for(int i=0;i<nums.size();i++){
          maxi=maxi-nums[i];
          ans=max(ans,maxi);
          if(maxi<0){
              maxi=0;
          }
          
      }
      return -(ans);
  }
};


//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        
        int ans = ob.smallestSumSubarray(a);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends