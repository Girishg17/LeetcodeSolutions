class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int>map(1e4+1,0);
        for(int i=0;i<nums.size();i++){
            map[nums[i]] += nums[i];
        }
        int maxi=0;
        for(int i=2;i<1e4+1;i++){
            map[i]= max(map[i-1],map[i]+map[i-2]);
        }
        return map[1e4];
        
    }
};