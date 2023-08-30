//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   int shortestDistance(int N, int M, vector<vector<int>>& arr, int X, int Y) {
    queue<pair<int,int>> q;
    int count = 0;
    
    if (arr[0][0] == 0) return -1;
    
    q.push({0, 0});
    int dir[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    vector<vector<int>> vis(N, vector<int>(M, 0));
    vis[0][0] = 1;
    
    while (!q.empty()) {
        int levelSize = q.size();  // Number of nodes at the current level
        
        for (int k = 0; k < levelSize; k++) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            if (row == X && col == Y) return count;
            
            for (int i = 0; i < 4; i++) {
                int newrow = row + dir[i][0];
                int newcol = col + dir[i][1];
                
                if (newrow >= 0 && newcol >= 0 && newrow < N && newcol < M &&
                    vis[newrow][newcol] == 0 && arr[newrow][newcol] == 1) {
                    vis[newrow][newcol] = 1;
                    q.push({newrow, newcol});
                }
            }
        }
        
        count++;  // Increment count after processing the whole level
    }
    
    return -1;
}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends