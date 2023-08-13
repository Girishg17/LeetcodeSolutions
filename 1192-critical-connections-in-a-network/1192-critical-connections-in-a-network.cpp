class Solution
{
    public:
        int timer = 1;
    void dfs(int src, int parent, vector<int> &vis, vector<vector< int>> &adj, int timin[], int low[], vector<vector < int>> &bridges)
    {
        vis[src] = 1;
        timin[src] = low[src] = timer;
        timer++;
        for (auto &it: adj[src])
        {
            if (it == parent) continue;
            if (vis[it] == 0)
            {
                dfs(it, src, vis, adj, timin, low, bridges);
                low[src] = min(low[src], low[it]);
                if (low[it] > timin[src])
                {

                    bridges.push_back({ src,
                        it });
                }
            }
            else
            {
                low[src] = min(low[src], low[it]);
            }
        }
    }
    vector<vector < int>> criticalConnections(int n, vector<vector < int>> &cont)
    {
       
        vector<vector < int>> adj(n);
        for (int i = 0; i < cont.size(); i++)
        {
            adj[cont[i][0]].push_back(cont[i][1]);
            adj[cont[i][1]].push_back(cont[i][0]);
        }
        vector<int> vis(n, 0);
        int timein[n];
        int low[n];
        vector<vector < int>> bridges;
        dfs(0, -1, vis, adj, timein, low, bridges);
        return bridges;
    }
};