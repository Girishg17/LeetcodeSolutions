class Solution {
public:
int maxsquare(vector<vector<char>>& matrix,int row,int col,int &maxi, vector<vector<int>>&dp){
    if(row>=matrix.size()||col>=matrix[0].size())return 0;
    if(dp[row][col]!=-1)return dp[row][col];
   int down= maxsquare(matrix,row+1,col,maxi,dp);
    int diagnal=maxsquare(matrix,row,col+1,maxi,dp);
   int side= maxsquare(matrix,row+1,col+1,maxi,dp);
   int x=0;
   if(matrix[row][col]=='1'){
       x=1+min(down,min(diagnal,side));
   }
   maxi=max(maxi,x);
   return dp[row][col]=x;



}
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        int maxi=0;
        
        maxsquare(matrix,0,0,maxi,dp);
        return maxi*maxi;
        
    }
};