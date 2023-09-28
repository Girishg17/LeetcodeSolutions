class Solution {
public:
    bool solve(vector<vector<char>>& board,vector<vector<int>>&vis,string word,int rw,int cl,int index){
        if(index==word.size())return true;

        vis[rw][cl]=1;
        int dir[][2]={{1,0},{0,1},{-1,0},{0,-1}};

        for(auto it:dir){
            int newrw=it[0]+rw;
            int newcl=it[1]+cl;
            if(newrw>=0&&newrw<board.size()&&newcl>=0&&newcl<board[0].size()&& vis[newrw][newcl]==0&&board[newrw][newcl]==word[index]){
                if(solve(board,vis,word,newrw,newcl,index+1)){
                    return true;
                }

            }
        }
        vis[rw][cl]=0;
        return false;




    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>>vis(board.size(),vector<int>(board[0].size(),0));
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){

                    if(solve(board,vis,word,i,j,1)){
                        return true;
                    }

                }
            }
        }
        return false;
        
    }
};