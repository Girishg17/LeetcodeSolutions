class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
       int maxval=0;
       if(nums.size()==0)return 0;
       if(nums.size()==1)return 1;
       vector<int>dp(nums.size(),1);
       vector<int>cnt(nums.size(),1);
       for(int i=0;i<nums.size();i++){
           for(int j=0;j<i;j++){
               if(nums[j]<nums[i]){
                   if(dp[j]+1==dp[i]){
                       cnt[i]+=cnt[j];
                   }
                   else if(dp[j]+1>dp[i]){
                          dp[i]=dp[j]+1;
                          cnt[i]=cnt[j];
                   }
                
             
               }
           }
       }
       int max_val=*max_element(dp.begin(),dp.end());
       int ans=0;
       for(int i=0;i<dp.size();i++){
           if(dp[i]==max_val){
               ans+=cnt[i];
           }
       }
       return ans;
     
       
        
        
    }
};
