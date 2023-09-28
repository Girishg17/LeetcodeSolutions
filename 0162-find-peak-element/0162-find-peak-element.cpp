class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int low=0;
        int high=nums.size();
        if(nums.size()==1)return 0;
        if(nums.size()==2){
            if(nums[0]>nums[1])return 0;
            else 
            {
                return 1;
            }
        }
    
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mid!=0 && mid!=nums.size()-1){
                if(nums[mid-1]<nums[mid]&&nums[mid]>nums[mid+1])return mid;
            }
            else if(mid==0){
                if(nums[mid]>nums[mid+1])return mid;
               
            }
            else if(mid==nums.size()-1){
                 if(nums[mid-1]<nums[mid])return mid;
            }
            if(mid>0&&nums[mid-1]>nums[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }

        }
        return 0;

        
    }
};