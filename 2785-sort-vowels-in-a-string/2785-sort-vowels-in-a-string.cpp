class Solution {
public:
   static bool isvowel(char i){
        if(i=='a'||i=='e' || i=='o' || i=='i' || i=='u'||i=='A'|| i=='E' || i=='O' || i=='I' || i=='U')return true;
        return false;
    } 
    string sortVowels(string s) {
    vector<char>arr;
        for(int i=0;i<s.size();i++){
            if(isvowel(s[i]))arr.push_back(s[i]);
        }
        sort(arr.begin(),arr.end());
        int j=0;
         for(int i=0;i<s.size();i++){
            if(isvowel(s[i])){
                s[i]=arr[j];
                j++;
            }
        }
        return s;

        
    }
};