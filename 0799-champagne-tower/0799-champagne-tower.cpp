class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {

        vector<vector<double>>dp(query_row+2,vector<double>(query_row+2,0));
        dp[0][0]=(double)poured;


for(int i=0;i<query_row;i++){
    for(int j=0;j<=i;j++){
        double left=(dp[i][j]-1.0)/2.0;
        if(left>0){
            dp[i+1][j]+=left;
            dp[i+1][j+1]+=left;
        }
    }

}

return min(1.0, dp[query_row][query_glass]);
        
    }
};