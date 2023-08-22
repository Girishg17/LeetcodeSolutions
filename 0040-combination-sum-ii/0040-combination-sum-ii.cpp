class Solution
{
    public:
        void solve(vector<int> &arr, int target, vector<vector< int >> &ans, vector< int > &temp, int index)
        {

            if (target == 0)
            {
                ans.push_back(temp);
                return;
            }
        
    for (int i = index; i < arr.size(); i++)
    {
        if (i>index &&arr[i ] ==arr[i-1])continue;
        if(arr[i]>target)break;
            if (arr[i] <= target)
            {
                temp.push_back(arr[i]);

                solve(arr, target - arr[i], ans, temp, i + 1);
                temp.pop_back();
            }
    }

  

}
vector<vector < int>> combinationSum2(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    vector<vector < int>> ans;
    vector<int> temp;
    solve(arr, target, ans, temp, 0);
    return ans;
    sort(ans.begin(), ans.end());

}
};