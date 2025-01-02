class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans(words.size(), 0);

        // Precompute the cumulative counts of valid vowel strings
        for (long i = 0; i < words.size(); i++) {
            if (isVowel(words[i][0]) && isVowel(words[i].back())) {
                ans[i] = (i == 0) ? 1 : ans[i - 1] + 1;
            } else {
                ans[i] = (i == 0) ? 0 : ans[i - 1];
            }
        }

        vector<int> sol;

        // Process the queries
        for (const auto& query : queries) {
            int left = query[0];
            int right = query[1];
            if (left == 0) {
                sol.push_back(ans[right]);
            } else {
                sol.push_back(ans[right] - ans[left - 1]);
            }
        }

        return sol;
    }

private:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};
