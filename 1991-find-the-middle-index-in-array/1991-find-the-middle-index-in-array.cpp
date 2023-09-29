class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        int prefix_sum=0;
        for(int i=0;i<nums.size();i++){
            
            prefix_sum+=nums[i];
            if(prefix_sum-nums[i]==total-prefix_sum)return i;

        }
        return -1;
        
    }
};