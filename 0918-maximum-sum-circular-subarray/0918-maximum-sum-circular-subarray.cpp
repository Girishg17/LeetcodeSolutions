class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
       int ans=INT_MIN;
       int negative_sum=INT_MIN;
       int prefix=0;
       int prefix_neg=0;
       int index=0;
       int total_sum=0;
       for(int i=0;i<nums.size();i++){
           prefix+=nums[i];
           prefix_neg=prefix_neg-nums[i];
           total_sum+=nums[i];
           ans=max(ans,prefix);
           negative_sum=max(negative_sum,prefix_neg);
           if(prefix<0){
               prefix=0;
              
           }
            if(prefix_neg<0){
               prefix_neg=0;
              
           }
       }
       if(ans<0)return ans;
      
     
     
     
       return max(ans,total_sum+negative_sum);
    }
};