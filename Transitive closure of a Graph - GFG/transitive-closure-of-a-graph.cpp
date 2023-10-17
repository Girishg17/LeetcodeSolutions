//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution{
public:
    vector<vector<int>> transitiveClosure(int n, vector<vector<int>> graph)
    {
        // code here
        
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if (i==j)graph[i][j]=1;
                    else if(graph[i][via]==0 || graph[via][j]==0)continue;
                    else{
                        graph[i][j]=1;
                    }
                    
                }
            }
        }
        return graph;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j=0;j<N;j++)
            cin>>graph[i][j];
        
        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for(int i = 0;i < N;i++)
            {for(int j = 0;j < N;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";}
    }
    return 0;
}
// } Driver Code Ends