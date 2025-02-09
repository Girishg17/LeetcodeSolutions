class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
       long long n=nums.size();
       long long total=n*(n-1)/2;
       long long good=0;
       unordered_map<long long,long long>mp;
       long long diff;
       for(int i=0;i<nums.size();i++){
            diff=nums[i]-i;
            if(mp.find(diff)!=mp.end()){
                good=good+mp[diff];
            }
            mp[diff]++;
       }
       return total-good;
    }
};