class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        dp[0]=1;
        for(int i=0;i<n;i++){
            if(dp[i]!=0){
                int j=1;
                while(i+j<n && j<=nums[i]){
                    dp[i+j]++;
                    j++;
                }
            }
        }
        if(dp[n-1]>=1)return true;
        return false;
    }
};