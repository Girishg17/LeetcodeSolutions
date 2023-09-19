class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
       priority_queue<pair<int,int>,vector<pair<int,int>>>pq;
        for(int i=0;i<groupSizes.size();i++){
            pq.push({groupSizes[i],i});
        }
       
       
        vector<vector<int>>ans;
        while(!pq.empty()){
           int top=pq.top().first;
           int value=pq.top().second;
           pq.pop();
           vector<int>temp;
           temp.push_back(value);
           top=top-1;
           while(!pq.empty()&&top--){
               temp.push_back(pq.top().second);
               pq.pop();
           }
           ans.push_back(temp);

        }
        return ans;
        
    }
};