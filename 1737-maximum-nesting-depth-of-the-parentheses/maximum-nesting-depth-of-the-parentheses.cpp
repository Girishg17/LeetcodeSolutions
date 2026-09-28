class Solution {
public:
    int maxDepth(string s) {
        int maxi=0;
        int temp=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')temp++;
            if(s[i]==')')temp--;
            maxi=max(maxi,temp);
        }
        return maxi;
    }
};