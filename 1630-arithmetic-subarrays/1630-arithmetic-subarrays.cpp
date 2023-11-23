class Solution {
public:
    bool check(vector<int>&nums){
        sort(nums.begin(),nums.end());

        int diff=nums[1]-nums[0];
        for(int i=2;i<nums.size();i++){
            if(nums[i]-nums[i-1]!=diff)return false;
        }
        return true;

    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    vector<bool>ans;
    for(int i=0;i<l.size();i++){
        vector<int>temp(nums.begin()+l[i],nums.begin()+r[i]+1);
        ans.push_back(check(temp));
    }
    return ans;
        
    }
};

