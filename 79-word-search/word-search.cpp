class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool solve(vector<vector<char>>& board, vector<vector<int>>& vis, int i,
               int j, int index, string word) {
        if (index >= word.size())
            return true;
      
        for (int k = 0; k < 4; k++) {
            int newrow = dir[k][0] + i;
            int newcol = dir[k][1] + j;
            if (newrow < board.size() && newcol < board[0].size() &&
                vis[newrow][newcol] == 0 &&
                board[newrow][newcol] == word[index]) {
                vis[newrow][newcol] = 1;
                if(solve(board, vis, newrow, newcol, index + 1, word))return true;

            }
        }
     vis[i][j]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] && vis[i][j] == 0) {
                    vis[i][j] = 1;
                    if (solve(board, vis, i, j, 1, word))
                        return true;
                        vis[i][j]=0;
                        
                }
            }
        }
        return false;
    }
};