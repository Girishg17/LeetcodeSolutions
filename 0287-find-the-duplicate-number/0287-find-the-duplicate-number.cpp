class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int max=INT_MIN;
        int max_el;
        for(auto it:mp){
            if(it.second>max){
                max_el=it.first;
                max=it.first;
            }

        }
        return max_el;

        
    }
};