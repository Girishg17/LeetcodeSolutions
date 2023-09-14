class Solution {
public:
 vector<string>path;
 bool dfs( unordered_map<string,vector<string>>&mp,string from,vector<string>&ans,int num){
         ans.push_back(from);
     if(ans.size()==num+1){
         path=ans;
         return true;
     }
   
    vector<string>&neighbours=mp[from];
    for(int i=0;i<neighbours.size();i++){
        string tocity=neighbours[i];
        neighbours.erase(neighbours.begin()+i);
        if(dfs(mp,tocity,ans,num)){
            return true;
        }
        
            
        neighbours.insert(neighbours.begin()+i,tocity);
        
    }
    ans.pop_back();
  
    return false;
 }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<tickets.size();i++){
            mp[tickets[i][0]].push_back(tickets[i][1]);
            if(mp[tickets[i][0]].size()>1)
            sort(mp[tickets[i][0]].begin(),mp[tickets[i][0]].end());
        }

        int numtickets=tickets.size();
        vector<string>ans;
        dfs(mp,"JFK",ans,numtickets);
        return path;

        
    }
};