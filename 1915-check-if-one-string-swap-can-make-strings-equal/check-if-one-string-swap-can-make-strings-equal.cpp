class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.size()!=s2.size())return false;
        int numofnonequal=0;
        int left=-1,right=-1;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                numofnonequal++;
                if(left==-1)left=i;
                else if(right==-1)right=i;
                }
        }
        if(numofnonequal==0)return true;
        if(numofnonequal==2 && s1[left]==s2[right] && s2[left]==s1[right])return true;
        return false;
        
    }
};