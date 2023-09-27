//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        
        int diff=INT_MAX;
        int close1=-1;
        int close2=-1;
        
        int low=0;
        int high=m-1;
        while(low<n&&high>=0){
         
            if(abs(x-arr[low]-brr[high])<diff){
                close1=arr[low];
                close2=brr[high];
                diff=abs(x-arr[low]-brr[high]);
                
                
            }
            if(arr[low]+brr[high]>x){
                high--;
            }
            else{
                low++;
            }
        }
        return {close1,close2};
        
        //code here
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends