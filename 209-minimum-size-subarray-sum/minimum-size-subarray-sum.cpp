class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0;
        int end = 0;
        int n = nums.size();
        int ans = INT_MAX;
        int sum = 0;
        while (end < n) {
            if (nums[end] == target)
                return 1;
            sum = sum + nums[end];

            while (sum >= target && start <= end) {
                ans = min(ans, end - start + 1);
                sum=sum-nums[start];
                start++;
            }
            end++;
        }
        if(ans==INT_MAX)return 0;
        return ans;
    }
};