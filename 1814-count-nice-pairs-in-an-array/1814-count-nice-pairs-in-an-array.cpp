class Solution {
public:
    #define MOD 1000000007
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            long long int temp = nums[i];
            long long int rev = 0;
            while(temp > 0) {
                int rem = temp % 10;
                rev = rev * 10 + rem;
                temp = temp / 10;
            }
            int diff = (nums[i] - rev + MOD) % MOD; // Ensure the difference is non-negative
            count = (count + mp[diff]) % MOD;
            mp[diff]++;
        }
        return count;
    }
};
