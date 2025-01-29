class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int start=0;
        int end=n;
        int mid;
        while(start<end){
            mid=start+(end-start)/2;
            if(nums[mid]==target)return mid;
            if(nums[mid]>target){
                end=mid;
            }
            else{
                start=mid+1;
            }
        }
        return -1;
    }
};