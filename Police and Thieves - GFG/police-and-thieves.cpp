//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int catchThieves(char arr[], int n, int k) 
    {
        // Code here 
        vector<int>p;
        vector<int>t;
        
        for(int i=0;i<n;i++){
            if(arr[i]=='P')p.push_back(i);
            else{
                t.push_back(i);
            }
            
        }
        int i=0;
        int j=0;
        int ans=0;
        while(i<p.size() && j<t.size()){
            if(abs(p[i]-t[j])<=k){
                i++;
                j++;
                ans++;
            }
            else if(p[i]< t[j]){
                i++;
            }
            else{
                j++;
                
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n >> k;
		char arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		Solution obj;
		cout<<obj.catchThieves(arr, n, k) << endl;
	}
	return 0; 
} 


// } Driver Code Ends