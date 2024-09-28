class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=0;
        int col=matrix[0].size()-1;
        while(row >=0 && row < matrix.size() && col>=0 && col < matrix[0].size()){
            if(target==matrix[row][col])return true;
            if(target <matrix[row][col])col--;
            else if(target>matrix[row][col])row++;
        }
        return false;

    }
};