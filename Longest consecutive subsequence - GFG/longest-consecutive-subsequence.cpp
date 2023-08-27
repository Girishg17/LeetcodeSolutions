//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      vector<int>num(1e5+1,-1);
      for(int i=0;i<N;i++){
          num[arr[i]]++;
      }
      int maxi=0;
      int ans=0;
    //   for(int i=0;i<10;i++){
    //       cout<<num[i];
    //   }
      for(int i=0;i<1e5+1;i++){
          if(num[i]!=-1){
              ans++;
          }
          else if(num[i]==-1){
              maxi=max(ans,maxi);
              ans=0;
          }
      }
      return max(maxi,ans);
      
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends