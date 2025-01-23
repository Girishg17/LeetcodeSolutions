class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int breakpoint=-1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                breakpoint=i;
            }
        }
        if(breakpoint==-1){
            sort(nums.begin(),nums.end());
            return;
        }
        else{
            int diff=INT_MAX;
            int swapnum=breakpoint;
            for(int i=breakpoint+1;i<nums.size();i++){
                if(nums[i]>nums[breakpoint] && diff>nums[i]-nums[breakpoint]){
                    swapnum=i;
                }
            }
            swap(nums[breakpoint],nums[swapnum]);
            sort(nums.begin()+breakpoint+1,nums.end());
            return;
        }
    }
};