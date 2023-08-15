class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans=1;
        int size=1;
     
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1])
           {
               size++;
                
           }
           else{
              
               size=1;
           }
           ans=max(ans,size);
          
        }
  
        
        // cout<<ans;
        // if(ans==0)return size;
      
       return ans;
        
    }
};