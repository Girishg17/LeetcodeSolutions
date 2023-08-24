class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
       int rowstart=0;
       int rowend=arr.size()-1;
       int colstart=0;int colend=arr[0].size()-1;
      
        vector<int>temp;
        while(colend>=colstart&&rowend>=rowstart){
       for(int i=colstart;i<=colend;i++){
           temp.push_back(arr[rowstart][i]);
           
       }
       
       rowstart++;
       
       for(int j=rowstart;j<=rowend;j++){
           temp.push_back(arr[j][colend]);
       }
       
       colend--;
       if(rowstart<=rowend){
       for(int k=colend;k>=colstart;k--){
           temp.push_back(arr[rowend][k]);
       }
       }
       rowend--;
       if(colstart<=colend){
       for(int m=rowend;m>=rowstart;m--){
           temp.push_back(arr[m][colstart]);
       }
       }
       colstart++;
        }

       return temp;
        
    }
};