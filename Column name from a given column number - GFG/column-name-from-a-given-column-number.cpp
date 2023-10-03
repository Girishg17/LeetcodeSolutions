//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string ans="";
        while(n>0){
             int rem=n%26;
            if(rem==0){
                 ans.push_back('Z');
                 n=(n/26)-1;
                 continue;
            }
           
            ans.push_back((rem-1)+'A');
            n=n/26;
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends