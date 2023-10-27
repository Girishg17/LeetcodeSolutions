

class Solution {
public:


  
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int prev=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            prev+=nums[i];
            int temp=prev-k;
            ans+=mp[temp];
            mp[prev]++;
        }
        return ans;
        }
        
      
    
};


