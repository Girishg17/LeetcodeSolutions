//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<long long >leftsmall(n);
        vector<long long >rightsmall(n);
        stack<long long >st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>= arr[i])st.pop();
            if(st.empty())leftsmall[i]=0;
            else{
                leftsmall[i]=st.top()+1;
            }
            st.push(i);
        }
          while (!st.empty())
    {
        st.pop();
    }
        
         for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>= arr[i])st.pop();
            if(st.empty())rightsmall[i]=n-1;
            else{
                rightsmall[i]=st.top()-1;
            }
            st.push(i);
        }
        // for(int i=0;i<n;i++)cout<<leftsmall[i]<<","<<rightsmall[i]<<endl;
        long long ans=LONG_LONG_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,(rightsmall[i]-leftsmall[i]+1)*arr[i]);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends