class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
     int c=0;
     int i=0;
     while(i<nums.size()-1&&nums[i]<nums[i+1]){
         i++;
     }
     if(i==nums.size()-1)return 0;
     i=i+1;
     int pivot=i;
     if(i==nums.size()-1)return 1;
     cout<<i<<endl;
    while(i<nums.size()-1&&nums[i]<nums[i+1]){
        i++;
        c++;
    }
   
   if(i!=nums.size()-1)return -1;
    if(nums[pivot]<nums[0]&&nums[nums.size()-1]<nums[0])
        {
            return nums.size()-pivot;
        }

    

     return -1;
        
    }
};