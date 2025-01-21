class Solution {
public:
 
    long long gridGame(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        long ts=0;
        long bs=0;
        long minimisedbyrob1=LONG_MAX;
        for(int i=0;i<n;i++){
            ts+=grid[0][i];
        }
        for(int i=0;i<n;i++){
            ts=ts-grid[0][i];
            minimisedbyrob1=min(minimisedbyrob1,max(ts,bs));
            bs=bs+grid[1][i];
        }
        return minimisedbyrob1;
    }
};