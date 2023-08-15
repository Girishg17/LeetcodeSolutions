class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        vector<unordered_map<int,int>>map(nums.size());
        int maxi=2;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                int diff=nums[i]-nums[j];
                if(map[j].find(diff)!=map[j].end()){
                    map[i][diff]=map[j][diff]+1;
                    
                }
                else{
                    map[i][diff]=2;
                }
                maxi=max(maxi,map[i][diff]);
            }
        }
        return maxi;

        
    }
};