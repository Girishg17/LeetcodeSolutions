class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int>ans;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                pq.push({i+j,j,nums[i][j]});
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top()[2]);
            pq.pop();
        }
        return ans;





        
        
        
    }
};