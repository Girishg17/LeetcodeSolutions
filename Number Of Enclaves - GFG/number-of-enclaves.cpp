//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int bfs(vector<vector<int>>&grid,int i,int j,bool &state){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()){
            state=true;
            return 0;
        }
        if(grid[i][j]==0)return 0;
        grid[i][j]=0;
        
        return 1+ bfs(grid,i+1,j,state)+ bfs(grid,i,j+1,state)+bfs(grid,i-1,j,state)+bfs(grid,i,j-1,state);
        
        
        
        
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    bool state=false;
                  int ans=  bfs(grid,i,j,state);
                    if(!state){
                        count+=ans;
                    }
                }
            }
        }
        return count;
        // Code here
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends