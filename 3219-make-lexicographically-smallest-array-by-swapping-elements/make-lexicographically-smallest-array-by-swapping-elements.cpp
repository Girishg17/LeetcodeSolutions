class Solution {
public:
    void updateResult(vector<int>& res, vector<int>& ind, vector<int>& val){ 
        sort(ind.begin(), ind.end()); sort(val.begin(), val.end());
        for(int i = 0; i < ind.size(); ++i) res[ind[i]] = val[i];
        ind.clear(); val.clear(); 
    }

    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> res(nums.size(), 0), index, values;
        multimap<int, int> mp;
        for(int i = 0; i < nums.size(); ++i) mp.insert({nums[i], i});
        auto lastKey = mp.begin()->first;
        for(auto [k,i]: mp){
            if(k - lastKey > limit) updateResult(res, index, values);
            index.push_back(i); values.push_back(k);
            lastKey = k;
        }
        updateResult(res, index, values);
        return res;
    }  
};