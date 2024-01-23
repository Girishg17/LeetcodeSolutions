#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

class Solution {
public:
    int solve(vector<string>& arr, int i, unordered_set<char>& st) {
        if (i >= arr.size()) return 0;
        
        // Check for duplicates within the same string
        unordered_set<char> uniqueChars;
        bool dup = false;
        for (int j = 0; j < arr[i].size(); j++) {
            char currentChar = arr[i][j];
            if (uniqueChars.count(currentChar) || st.count(currentChar)) {
                dup = true;
                break;
            }
            uniqueChars.insert(currentChar);
        }

        int take = 0;
        if (!dup) {
            for (int j = 0; j < arr[i].size(); j++) {
                st.insert(arr[i][j]);
            }
            take = arr[i].size() + solve(arr, i + 1, st);
            for (int j = 0; j < arr[i].size(); j++) {
                st.erase(arr[i][j]);
            }
        }

        int dontake = solve(arr, i + 1, st);

        return max(take, dontake);
    }

    int maxLength(vector<string>& arr) {
        unordered_set<char> st;
        return solve(arr, 0, st);
    }
};
