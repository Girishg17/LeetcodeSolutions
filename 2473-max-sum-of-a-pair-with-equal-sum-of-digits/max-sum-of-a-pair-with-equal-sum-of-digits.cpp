class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        int sum,temp;
        for(int i=0;i<nums.size();i++){
             temp=nums[i];
             sum=0;
            while(temp>0){
                sum=sum+temp%10;
                temp=temp/10;
            }
            mp[sum].push_back(nums[i]);
        }
        int ans=-1;
        for(auto it:mp){
            if(it.second.size()<2)continue;
            sort(it.second.begin(),it.second.end());
            int total=it.second[it.second.size()-1]+it.second[it.second.size()-2];
            if(total>ans)ans=total;
            
        }
        return ans;
    }
};