class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool inc1=false;
        bool dec1=false;
        bool inc2=false;
        int i=0;
        int j=1;
        while(i<nums.size()-1 && j<nums.size() && nums[i]<nums[j]){
            i++;
            j++;
            if(inc1==false)inc1=true;

        }
        while(i<nums.size()-1 && j<nums.size() && nums[i]>nums[j]){
            i++;
            j++;
            if(dec1==false)dec1=true;

        }

        while(i<nums.size()-1 && j<nums.size() && nums[i]<nums[j]){
            i++;
            j++;
            if(inc2==false)inc2=true;

        }
        if(j!=nums.size())return false;
        if(inc1 && dec1 && inc2)return true;
        return false;
        
    }
};