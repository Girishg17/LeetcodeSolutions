//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        int breakpt=-1;
        for(int i=0;i<N-1;i++){
            if(arr[i]<arr[i+1])breakpt=i;
            
        }
      
        if(breakpt==-1){ reverse(arr.begin(),arr.end());
        return arr;
        }
        int min_diffrece=INT_MAX;
        int min_idex=-1;
        for(int j=breakpt+1;j<N;j++){
            if(arr[j]>arr[breakpt] && arr[j]-arr[breakpt]<min_diffrece){
                min_idex=j;
                min_diffrece=arr[j]-arr[breakpt];
            }
            
        }
        
        swap(arr[breakpt],arr[min_idex]);
        
        sort(arr.begin()+breakpt+1,arr.end());
        return arr;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends