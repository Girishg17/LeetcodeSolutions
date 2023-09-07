class Solution
{
    public:
        int findMin(vector<int> &nums)
        {
            int start = 0;
            int end = nums.size() - 1;
            while (start <end)
            {
               if(nums[start]<=nums[end])return nums[start];
               int mid=start+(end-start)/2;
               if(nums[mid]>nums[end]){
                   start=mid+1;
               }
               else if(nums[start]>nums[end]){
                   end=mid;
               }
            }
            if(nums[start]<=nums[end])return nums[start];
            return -1;
        }
};