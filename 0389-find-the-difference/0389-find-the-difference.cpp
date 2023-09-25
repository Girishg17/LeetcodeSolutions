class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int j=0;
        for(int i=0;i<t.size();i++){
            if(t[i]!=s[j])return t[i];
            j++;
            
        }
        return 'a';
        
    }
};