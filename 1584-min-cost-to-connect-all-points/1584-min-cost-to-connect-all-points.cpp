class Disjoint{
    vector<int>parent;
    vector<int>rank;
    public:
    Disjoint(int n){
        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findParent(int node){
        if(node==parent[node]){return node;}
        return parent[node]=findParent(parent[node]);
    }
    void Unioninsert(int u,int v){
        int ultimater_parent_u=findParent(u);
        int ultimater_parent_v=findParent(v);
        if(ultimater_parent_u==ultimater_parent_v)return;
        else if(rank[ultimater_parent_u]<rank[ultimater_parent_v]){
            parent[ultimater_parent_u]=ultimater_parent_v;
        }
        else if(rank[ultimater_parent_v]<rank[ultimater_parent_u]){
            parent[ultimater_parent_v]=ultimater_parent_u;
        }
        else{
             parent[ultimater_parent_v]=ultimater_parent_u;
             rank[ultimater_parent_u]++;
        }
    }
    };


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int,pair<int,int>>>edges;
        int count=0;
        for(int i=0;i<points.size()-1;i++){
            for(int j=i+1;j<points.size();j++){
                int dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({abs(dist),{i,j}});
                edges.push_back({abs(dist),{j,i}});
            }
        }
         sort(edges.begin(),edges.end());
          Disjoint ds(points.size());
    int ans=0;
    for(auto &it:edges){
        int wt=it.first;
        int u=it.second.first;
        int v=it.second.second;
        if(ds.findParent(u)!=ds.findParent(v)){
            ans+=wt;
            ds.Unioninsert(u,v);
        }

    }
    return ans;
        
    }
};