class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start=-1;
        int end=-1;
        if(nums.size()==1||nums.size()==0)return 0;
        for(int i=0;i<nums.size()-1;i++){
            bool flag=false;
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]>nums[j]){
                    flag=true;
                    start=i;
                    break;

                }
            }
            if(flag){
                break;
            }
        }
         for(int i=nums.size()-1;i>=1;i--){
            bool flag=false;
            for(int j=i-1;j>=0;j--){
                if(nums[i]<nums[j]){
                    flag=true;
                    end=i;
                    break;

                }
            }
            if(flag){
                break;
            }
        }
      
        if(end==-1&&start==-1)return 0;
        else if(end==-1){
            nums.size()-start;
        }
        else if(start==-1){
            return end;
        }
        return end-start+1;
        
    }
};