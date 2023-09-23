class Solution {
public:

    void gameOfLife(vector<vector<int>>& b) {
        vector<vector<int>>board(b);
        int dir[][2]={{0,1},{1,0},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==1){
                    int count=0;
               for(auto &it:dir){
                   int newrow=it[0]+i;
                   int newcol=it[1]+j;
                   if(newrow>=0 && newrow<board.size()&& newcol>=0 && newcol< board[0].size() ){
                       if(board[newrow][newcol]==1)count++;
                   }
                 
               }
                 if(count<2||count>3)b[i][j]=0;

                }
                else{

                    int count=0;
               for(auto &it:dir){
                   int newrow=it[0]+i;
                   int newcol=it[1]+j;
                   if(newrow>=0 && newrow<board.size()&& newcol>=0 && newcol< board[0].size() ){
                       if(board[newrow][newcol]==1)count++;
                   }
                   
               }
                 if(count==3)b[i][j]=1;
                }
                

            }
        }
       
        
    }
};