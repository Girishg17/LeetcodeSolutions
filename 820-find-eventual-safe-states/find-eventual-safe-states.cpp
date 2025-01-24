

class Solution {
public:
     bool  checkdfs(int i,vector<vector<int>>& graph,vector<int> &vis,vector<int> &path,vector<bool> &ans){
  vis[i]=1;
  path[i]=1;
  for(auto it:graph[i]){

      if(!vis[it]){
        
            ans[i] = ans[i] && checkdfs(it,graph,vis,path,ans);
          }
          else{
            if(path[it]==1){
                ans[i] = false;
            }
            else{
                ans[i] = ans[i] && ans[it];
            }
          }
      }
      path[i]=0;
      return ans[i];

  }
     
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>vis(graph.size(),0);
        vector<bool>ans(graph.size(),true);
        vector<int>pathvis(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            if(!vis[i]){
               ans[i]= checkdfs(i,graph,vis,pathvis,ans);
            }
        }
        vector<int>final;
       for(int i=0;i<ans.size();i++){
           if(ans[i]){
               final.push_back(i);
           }
       }
       return final;

        
        
    }


    
};