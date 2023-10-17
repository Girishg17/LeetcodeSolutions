class Solution {
public:
    void dfs(int src,vector<vector<int>>&gp,vector<int>& informTime,int &maxi,int sum){
        sum=sum+informTime[src];
        maxi=max(maxi,sum);
        for(auto it:gp[src]){
            
                dfs(it,gp,informTime,maxi,sum);

            
        }
        return ;


    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>>gp(n);
      
        for(int i=0;i<n;i++){
            if(i!=headID)
            gp[manager[i]].push_back(i);
        }
        int maxiTime=0;
       dfs(headID,gp,informTime,maxiTime,0);

return maxiTime;
        
    }
};