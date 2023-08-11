class Solution {
public:
    int minpath(vector<vector<int>>& t,int row,int col,vector<vector<int>>& dp){
        if(row>=t.size()&&col>=t[col].size())return 0;
        if(dp[row][col]!=-1)return dp[row][col];
        if(row==t.size()-1){
            return t[row][col];
        }
        

       return dp[row][col]=min( minpath(t,row+1,col,dp),minpath(t,row+1,col+1,dp))+t[row][col];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        // for(int i=1;i<triangle.size();i++){
        //     for(int j=0;j<triangle[i].size();j++){
        //         if(j==0){
        //             triangle[i][j]=triangle[i][j]+triangle[i-1][j];
               
        //         }
        //         else if(j==triangle[i].size()-1){
        //             triangle[i][j]=triangle[i][j]+triangle[i-1][j-1];
        //         }
        //         else{
        //              triangle[i][j]=min(triangle[i-1][j],triangle[i-1][j-1])+triangle[i][j];
        //         }
        //     }
        // }

         
        // int maxi=INT_MAX;
        // for(int i=0;i<triangle[triangle.size()-1].size();i++){
        //     if(triangle[triangle.size()-1][i]<maxi){
        //         maxi=triangle[triangle.size()-1][i];
                
        //     }
        // }
         vector<vector<int>> dp(triangle.size(),vector<int>(triangle.size(),-1));
        return minpath(triangle,0,0,dp);
    }
};