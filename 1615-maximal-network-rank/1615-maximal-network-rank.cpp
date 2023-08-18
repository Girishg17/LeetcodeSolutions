class Solution {
public:
int recursion(vector<vector<int>>&adj,int n,vector<int>&vis,vector<int>&pathvis){
    vis[n]=1;
    pathvis[n]=1;
    int c=0;
   
    for(int i=0;i<adj[n].size();i++){
        if(vis[i]==0&&pathvis[i]==0){
            c=1+ recursion(adj,i,vis,pathvis);

        }
    }
     pathvis[n]=0;
     return c;
}
    
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        map<int,int>mp;
        vector<vector<int>>adjlist(n,vector<int>(n,0));
        for(auto &it:roads){
            adjlist[it[0]][it[1]]=1;
            adjlist[it[1]][it[0]]=1;
            mp[it[0]]++;
            mp[it[1]]++;
        }
        int ans=0;
      for(int i=0;i<n;i++){
          for(int j=i+1;j<n;j++){
              int rank=mp[i]+mp[j];
              if(adjlist[i][j]==1){
                  rank--;
              }
              ans=max(ans,rank);
          }

      }
      return ans;
        
    }
};