//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        sort(a,a+n);
        int i=0;
        while(k>0 && i<n && a[i]<0){
            a[i]=-(a[i]);
            i++;
            k--;
        }
        if( k%2==1){
            sort(a,a+n);
            a[0]=-(a[0]);
        }
        // for(int i=0;i<n;i++){
        //     cout<<a[i]<<endl;
        // }
        long long int sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
        }
        return sum;
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
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}
// } Driver Code Ends