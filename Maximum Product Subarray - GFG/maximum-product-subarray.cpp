//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    
	    long long prefix=1;
	    long long suffix=1;
	    long long ans=LONG_MIN;
	    if(n==1)return arr[0];
	    for(int i=0;i<n;i++){
	        if(suffix==0){
	            suffix=1;
	        }
	        if(prefix==0){prefix=1;}
	        prefix=prefix*arr[i];
	        suffix=suffix*arr[n-i-1];
	        ans=max(ans,max(prefix,suffix));
	        
	        
	    }
	    return ans;
	    // code here
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends