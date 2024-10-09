class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n,vector<int>(n,0));
        int rowstart=0;
        int rowend=n-1;
        int colstart=0;
        int colend=n-1;
        int number=1;
        int square;
        while(rowstart<=rowend && colstart<=colend){
            for(int i=colstart;i<=colend;i++){
                
                matrix[rowstart][i]=number;
                number++;
            }
            rowstart++;
            for(int i=rowstart;i<=rowend;i++){
                
                matrix[i][colend]=number;
                number++;
            }
            colend--;
            for(int j=colend;j>=colstart;j--){
               
                matrix[rowend][j]=number;
                number++;
            }
            rowend--;
            for(int j=rowend;j>=rowstart;j--){
                matrix[j][colstart]=number;
                number++;
            }
            colstart++;
        }
        return matrix;

    }
};