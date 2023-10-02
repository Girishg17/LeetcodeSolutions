class Solution {
public:
    long long countVowels(string word) {
        
        long long count_non = 0;
        long long ans=0;
      

        for (int i = 0; i <word.size(); i++) {
            
            if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
                count_non+=i+1;
                
            } 
            ans+=count_non;
        }
        return ans;

       
    }
};
