class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int startw;
        int startp;
        int ans=0;
        for (int i=0;i<words.size();i++){
            string word=words[i];
            startw=0;
            startp=0;
            while(startw< word.size() && startp < pref.size() && word[startw]== pref[startp]){
                startw++;
                startp++;
            }
            if(startp>=pref.size()){
                ans++;
            }

        }
        return ans;
        
    }
};