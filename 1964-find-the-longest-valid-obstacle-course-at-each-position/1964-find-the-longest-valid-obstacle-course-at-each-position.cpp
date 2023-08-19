class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> answer;
        vector<int> ans;
        answer.push_back(1);
        ans.push_back(obstacles[0]);
        
        for (int i = 1; i < obstacles.size(); i++) {
            if (obstacles[i] >= ans.back()) {
                ans.push_back(obstacles[i]);
                answer.push_back(ans.size());
            } else {
                int index = upper_bound(ans.begin(), ans.end(), obstacles[i]) - ans.begin();
                ans[index] = obstacles[i];
                answer.push_back(index + 1); 
            }
        }
        return answer;
    }
};
