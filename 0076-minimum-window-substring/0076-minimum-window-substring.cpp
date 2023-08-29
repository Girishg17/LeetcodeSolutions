class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) {
            return "";
        }
        
        unordered_map<char, int> dp;
        int i = 0;
        int j = 0;
        int count = 0;
        int min_length = INT_MAX;
        int start, end;
        
        for (char c : t) {
            dp[c]++;
        }
        
        count = dp.size();  // Number of unique characters in t
        
        while (j < s.size()) {
            if (dp.find(s[j]) != dp.end()) {
                dp[s[j]]--;
                if (dp[s[j]] == 0) {
                    count--;
                }
            }
            
            while (count == 0) {
                if (j - i + 1 < min_length) {
                    min_length = j - i + 1;
                    start = i;
                    end = j;
                }
                
                if (dp.find(s[i]) != dp.end()) {
                    dp[s[i]]++;
                    if (dp[s[i]] > 0) {
                        count++;
                    }
                }
                
                i++;
            }
            
            j++;
        }
        
        if (min_length == INT_MAX) {
            return "";
        }
        
        return s.substr(start, min_length);
    }
};
