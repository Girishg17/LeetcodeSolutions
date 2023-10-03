class Solution {
public:
    int solve(vector<int>&arr){
        arr[1]=max(arr[0],arr[1]);
        for(int i=2;i<arr.size();i++){
            arr[i]=max(arr[i-1],arr[i]+arr[i-2]);
        }
        return arr[arr.size()-1];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        if(nums.size()==2)return max(nums[0],nums[1]);
      
       vector<int>temp1;
       vector<int>temp2;
       for(int i=0;i<nums.size();i++){
           if(i!=0)temp1.push_back(nums[i]);
           if(i!=nums.size()-1)temp2.push_back(nums[i]);
       }
       return max(solve(temp1),solve(temp2));
    }
};