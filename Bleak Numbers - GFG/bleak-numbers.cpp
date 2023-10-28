//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
public:
    int is_bleak(int n)
    {
        int z=max(1,n-32);
        
        for(int i=z;i<=n;i++){
            
            int ct=i+ __builtin_popcount(i);
            
            if(ct==n)
            return 0;
        }
        
        return 1;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends