//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

   class Solution {
public:
    int countWays(string S1, string S2) {
        return countRecursive(S1, S2, 0, 0);
    }

    int countRecursive(string& s1, string& s2, int i, int j) {
        if (j == s2.size()) {
            return 1; // If second string is exhausted, we found a valid transformation
        }

        if (i == s1.size()) {
            return 0; // If first string is exhausted, no more transformations are possible
        }

        int ways = 0;

        // If characters match, we can either proceed or replace and proceed
        if (s1[i] == s2[j]) {
            ways += countRecursive(s1, s2, i + 1, j + 1);
        }

        // Skip the current character in s1
        ways += countRecursive(s1, s2, i + 1, j);

        return ways;
    }
};

   



//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1;
        cin>>S2;
        
        Solution ob;
        cout<<ob.countWays(S1, S2)<<endl;
    }
    return 0;
}
// } Driver Code Ends