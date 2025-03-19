class Solution {
public:
    int minOperations(vector<int>& nums) {
     int c=0;
     int i=0;
     while(i<nums.size()){
        if(nums[i]==0){
            int k=0;
            while(i+2<nums.size()  && k<=2){
                
                nums[i+k]=!nums[i+k];
                k++;
            }
            c++;
        }
        i++;
     }
     for(int j=0;j<nums.size();j++){
        if(nums[j]==0)return -1;
     }
     return c;
    }
};