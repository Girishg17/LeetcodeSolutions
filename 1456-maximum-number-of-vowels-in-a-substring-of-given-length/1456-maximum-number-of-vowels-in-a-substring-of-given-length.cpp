class Solution {
public:
    int maxVowels(string s, int k) {
        int start=0;
        int end=0;
        int maxlen=0;
        int count=0;
        int length=0;
        while(end<s.size()){
            if(s[end]=='a'||s[end]=='e'||s[end]=='i'||s[end]=='o'||s[end]=='u'){
                count++;
            }

        length++;
        if(length==k){
            maxlen=max(maxlen,count);
            if(s[start]=='a'||s[start]=='e'||s[start]=='i'||s[start]=='o'||s[start]=='u'){
                count--;
            }
            length--;
            start++;
        }
        end++;


        }
        return max(maxlen,count);
    }
};