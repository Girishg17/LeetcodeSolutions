class Solution {
public:
    bool isValid(int row,vector<string>&temp,int col){

        int temprow=row;
        while(temprow>=0){
            if(temp[temprow][col]!='.')return false;
            temprow--;

        }
        temprow=row;
        int tempcol=col;
        while(temprow>=0&&tempcol>=0){
             if(temp[temprow][tempcol]!='.')return false;
            temprow--;
            tempcol--;

        }

         temprow=row;
         tempcol=col;
        while(temprow>=0&&tempcol<temp.size()){
             if(temp[temprow][tempcol]!='.')return false;
            temprow--;
            tempcol++;

        }
        return true;

    }
    void solve(vector<vector<string>>&finalans,vector<string>&temp,int n,int row){
        if(row==n){
            finalans.push_back(temp);
            return ;
        }
        for(int i=0;i<n;i++){
            if(isValid(row,temp,i)){
                temp[row][i]='Q';
                solve(finalans,temp,n,row+1);
                temp[row][i]='.';
            }
        }


    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>finalans;
        vector<string>temp(n);
        for(int i=0;i<n;i++){
           
            for(int j=0;j<n;j++){
                temp[i].push_back('.');
            }
            
        }
        
        solve(finalans,temp,n,0);
        
        return finalans;
        
    }
};