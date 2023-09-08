class Solution {
public:
    vector<vector<int>> generate(int numRows) {
         vector<vector<int>> result;
        for(int i=0;i<numRows;i++){
            vector<int> c(i+1);
            result.push_back(c);
            for(int j=0;j<=i;j++){
                if(i==j){
                    result[i][j]=1;
                }
               else if(j==0){
                    result[i][j]=1;
                }
                else{
                    
                    result[i][j]=result[i-1][j-1]+result[i-1][j];
                }
                
            }
            
        }
        return result;
    
    
    }
};