//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:

    string rremove(string s){
        // code here
        int i=0;
        string temp="";
        int n=s.size();
       for(int i=0;i<n;i++)
        {
            if(s[i]==s[i+1]||s[i]==s[i-1])continue;
            else{
                temp.push_back(s[i]);
            }
         
        }
        if(temp==s)return temp;
      return  rremove(temp);
     
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.rremove(s) << "\n";
    }
    return 0;
}
// } Driver Code Ends