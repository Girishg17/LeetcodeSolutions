class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>ans(n,0);
        for(int i=0;i<edges.size();i++){
            ans[edges[i][1]]++;
        }
        vector<int>total;

        for(int i=0;i<n;i++){
            if(ans[i]==0){
                total.push_back(i);
            }
        }
        return total;

        
    }
};