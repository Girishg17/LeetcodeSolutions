class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=mp[nums[i]];
            mp[nums[i]]++;
        }
        return ans;
        
    }
};