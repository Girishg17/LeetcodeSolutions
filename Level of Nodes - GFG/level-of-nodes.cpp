//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    queue<pair<int,int>>q;
	    vector<int>v(V,0);
	   
	    q.push({0,0});
	   
	    while(!q.empty()){
	        int val=q.front().first;
	        int level=q.front().second;
	        q.pop();
	         v[val]=1;
	        if(val==X)return level;
	         
	        for(auto it:adj[val]){
	            if(v[it]==0)
	                q.push({it,level+1});
	        }
	       
	    }
	    return -1;
	    
	}
	
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends