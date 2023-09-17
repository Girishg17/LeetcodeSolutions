class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int finalstate=(1<<graph.size())-1;
        vector<vector<int>>vis(graph.size(),vector<int>(finalstate+1,0));
        queue<pair<int,int>>q;
        for(int i=0;i<graph.size();i++){
            q.push({i,1<<i});
        }
        int shortestpath=0;
        while(!q.empty()){
            int size=q.size();
            shortestpath++;
            for(int i=0;i<size;i++){
                int node=q.front().first;
                int visitedbit=q.front().second;
                q.pop();
                for(auto it:graph[node]){
                    int newvis=visitedbit | (1<<it);
                    if(vis[it][newvis]==0){
                        vis[it][newvis]=1;
                        q.push({it,newvis});
                        if(newvis==finalstate)return shortestpath;
                    }
                    else{
                        continue;
                    }
                }

            }
            
        }
        return 0;
        
        
    }
};