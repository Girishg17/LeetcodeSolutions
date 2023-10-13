class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int i=0;
        int j=0;
         while(j<matrix[0].size() && i< matrix.size()){
             int row=i+1;
             int col=j+1;
             while(row<matrix.size() && col<matrix[0].size() ){
                 if(matrix[row][col]!=matrix[i][j])return false;
                 row++;
                 col++;
             }
             j++;
             if(j==matrix[0].size()){
                 i++;
                 j=0;
             }
         }
            return true;
        
    }
};