//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    static bool mycmp(vector<int>&a , vector<int>&b)
    {
        return a[1]<b[1];
    }
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        
        vector<vector<int>>arr;
        for(int i=0;i<N ;i++){
            arr.push_back({S[i],F[i],i+1});
         
        }
        sort(arr.begin(),arr.end(),mycmp);
        
        int lastend=arr[0][1];
        vector<int>ans;
        ans.push_back(arr[0][2]);
        for(int i=1;i<N ;i++){
            if(arr[i][0]>lastend){
                ans.push_back(arr[i][2]);
                lastend=arr[i][1];
            }
        }
        
    
    sort(ans.begin(),ans.end());
    return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends