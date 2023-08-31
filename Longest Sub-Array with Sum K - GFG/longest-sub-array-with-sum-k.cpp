//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
 
      

    int lenOfLongSubarr(int arr[],  int n, int k) 
    { 
    map<int,int>mp;
    int maxlen=INT_MIN;
    int prefixsum=0;
    for(int i=0;i<n;i++){
        prefixsum=prefixsum+arr[i];
        if(prefixsum==k){
            maxlen=max(maxlen,i+1);
        }
       else if(mp.find(prefixsum-k)!=mp.end()){
            maxlen=max(maxlen,i-mp[prefixsum-k]);
        }
        if(mp.find(prefixsum)==mp.end()){
            mp[prefixsum]=i;
        }
        
    }
    if(maxlen==INT_MIN)return 0;
    return maxlen;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends