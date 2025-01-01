class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int curr=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            if(mp.find(curr-k)!=mp.end()){
                ans+=mp[curr-k];
            }
            mp[curr]++;
        }
        return ans;
        
    }
};