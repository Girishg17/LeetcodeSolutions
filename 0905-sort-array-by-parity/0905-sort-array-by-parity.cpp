class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int start=0;
        while(start<nums.size()&&(nums[start]&1)==0){
            
            start++;
        }
        // cout<<start;
        if(start==nums.size())return nums;

        int end=start+1;
        while(end<nums.size()){
            if((nums[end]&1)==0){
               
                int temp=nums[end];
                nums[end]=nums[start];
                nums[start]=temp;
                start++;
            }
            end++;
        }
        return nums;
        
    }
};