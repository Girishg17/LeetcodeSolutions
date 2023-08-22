class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int longstreak=0;
        for(int i=0;i<nums.size();i++){
            if(!st.count(nums[i]-1)){
                int curr_num=nums[i];
                int count=1;
                while(st.count(curr_num+1)){
                    count++;
                    curr_num=curr_num+1;
                }
                if(longstreak<count){
                    longstreak=count;
                }

            }

        }
        return longstreak;
        
    }
};