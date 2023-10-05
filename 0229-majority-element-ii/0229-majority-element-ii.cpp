class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size()==1)return {nums[0]};
        int size=nums.size()/3;
        vector<int>ans;
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(i==nums.size()-1){
                if(nums[i]==nums[i-1]){
                    count++;
                    if(count>size){
                        ans.push_back(nums[i]);
                    }
                    
                }
                else{
                    if(1>size){
                        ans.push_back(nums[i]);
                    }
                
                }
            }
          else  if(nums[i]==nums[i+1]){
                count++;
            }
            else{
               
                 count++;
                    if(count>size){
                        ans.push_back(nums[i]);
                    }
                    count=0;

            }

        }
        return ans;
        
    }
};