class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][2],times[i][1]});
        }
        pq.push({0,k});
        while(!pq.empty()){
            int node=pq.top().second;
            int wt=pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                
                int newwt=wt+it.first;
                if(dist[it.second]>newwt){
                    dist[it.second]=newwt;
                    pq.push({newwt,it.second});
                }
                else{
                    continue;
                }

            }

        }
        
        int maxi=*max_element(dist.begin()+1,dist.end());
        if(maxi==INT_MAX)return -1;
        return maxi;

        
    }
};