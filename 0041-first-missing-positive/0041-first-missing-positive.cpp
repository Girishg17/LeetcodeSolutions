class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int>st;
       for(int i=0;i<nums.size();i++){
           st.insert(nums[i]);

       }
       int ans=1;
       for(int i=1;i<=nums.size();i++){
           if(st.find(i)!=st.end())ans++;
           else{
               return ans;
           }
       }
       return ans;
        
    }
};