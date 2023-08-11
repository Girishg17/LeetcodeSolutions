class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(),0);
        dp[0]=1;
        for(int i=0;i<nums.size();i++){
            if(dp[i]!=0){
            int j=1;
            while(j<=nums[i]&&i+j<nums.size()){
                if(i+j==nums.size()-1)return true;
                dp[i+j]++;
                j++;
            }
            
            }
        }
        
        if(dp[nums.size()-1]==0)return false;
        return true;
        
    }
};