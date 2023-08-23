class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0;
        int r=numbers.size()-1;
        while(l<r){
            
            if(numbers[l]+numbers[r]==target){
                vector<int>ans;
                ans.push_back(l+1);
                ans.push_back(r+1);
                return ans;
            }
            if(numbers[l]+numbers[r]>target){
                r=r-1;
            }
            else{
                l=l+1;
            }
            
        }
        return {};
        
    }
};