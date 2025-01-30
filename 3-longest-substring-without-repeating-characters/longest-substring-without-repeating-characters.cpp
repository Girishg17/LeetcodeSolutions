class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start=0;
        int ans=0;
        set<char>st;
        int end=0;
        int n=s.size();
        while(end<n && start<=end){
            if(st.find(s[end])==st.end()){
                ans=max(ans,end-start+1);
                st.insert(s[end]);
                end++;
            }
            else{
                st.erase(s[start]);
                start++;
               
            }
          
        }
        return ans;

    }
};