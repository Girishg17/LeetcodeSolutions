class Graph {
public:
   int node;
   vector<vector<pair<int,int>>>adj;
    Graph(int n, vector<vector<int>>& edges) {
        node=n;
        adj.resize(node);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][2],edges[i][1]});

        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[2],edge[1]});
        
    }
    
  
    int shortestPath(int node1, int node2) {
    vector<int> dist(node, INT_MAX);
    dist[node1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, node1});

    while (!pq.empty()) {
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node]) {
            int newwt = wt + it.first;
            if (dist[it.second] > newwt) {
                dist[it.second] = newwt;
                pq.push({newwt, it.second});
            }
        }
    }
    return ((dist[node2]==INT_MAX)?-1:dist[node2]);
}


    
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */