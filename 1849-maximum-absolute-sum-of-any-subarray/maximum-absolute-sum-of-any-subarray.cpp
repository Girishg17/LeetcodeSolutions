class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        int prefm=0;
        int pref=0;
        for(int i=0;i<nums.size();i++){
            pref+=nums[i];
            prefm+=nums[i];
            mini=min(mini,prefm);
            maxi=max(maxi,pref);
            if(pref<0)pref=0;
            if(prefm>0)prefm=0;
        }
        return max(maxi,abs(mini));

    }
};