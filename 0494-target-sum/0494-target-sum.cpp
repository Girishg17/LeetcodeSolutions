class Solution {
public:
    int solve(vector<int>&nums,int &target,int i,int sum,vector<unordered_map<int,int>>&mp){
        if(i==nums.size()){
            if(target==sum)return 1;
            return 0;
        }
        if(mp[i].find(sum)!=mp[i].end())return mp[i][sum];
        int add=solve(nums,target,i+1,sum+nums[i],mp);
        int dontadd=solve(nums,target,i+1,-nums[i]+sum,mp);
        return mp[i][sum]=add+dontadd;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<unordered_map<int,int>>mp(nums.size()+1);
        return solve(nums,target,0,0,mp);
    }
};