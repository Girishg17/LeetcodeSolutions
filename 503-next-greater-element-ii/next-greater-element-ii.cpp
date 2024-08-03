// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& nums) {
//         vector<int>ans(nums.size());
//         stack<int>st;
//         for(int i=nums.size()-1;i>=0;i--){
//             while(!st.empty() && st.top()<=nums[i])st.pop();
//             if(st.empty())ans[i]=-1;
//             else{
//                 ans[i]=st.top();
//             }
//             st.push(nums[i]);
//         }
//         for(int i=nums.size()-1;i>=0 ;i--){
//             while(!st.empty() && st.top()<=nums[i]){
//                 st.pop();
//             }
//             if(ans[i]==-1 && !st.empty()){
//                 ans[i]=st.top();
//             }
//         }
//         return ans;
//     }
// };//this also works but there is confusion in question 

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1); // Initialize answer vector with -1
        stack<int> st;

        // Process the elements in reverse order twice to handle the circular nature
        for (int i = 2 * n - 1; i >= 0; --i) {
            int idx = i % n;
            while (!st.empty() && st.top() <= nums[idx]) {
                st.pop();
            }
            if (i < n) { // Only fill answers for the first pass
                if (!st.empty()) {
                    ans[idx] = st.top();
                }
            }
            st.push(nums[idx]);
        }
        
        return ans;
    }
};
