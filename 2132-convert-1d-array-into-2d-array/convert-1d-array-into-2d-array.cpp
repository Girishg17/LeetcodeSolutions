class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int size=m*n;
        
        vector<vector<int>> matrix(m, vector<int>(n));
        vector<vector<int>>ans;
        if(original.size()!=size)return ans; 
        int i = 0;
        int j = 0;
        for (int k = 0; k < original.size(); k++) {
            if (j >= n){
                j = 0;
                i++;
            }
            if(j<n && i<m)
            matrix[i][j] = original[k];
            j++;
        }
        return matrix;
    }
};