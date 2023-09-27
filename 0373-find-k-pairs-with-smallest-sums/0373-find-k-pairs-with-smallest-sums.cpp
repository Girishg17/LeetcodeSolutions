class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        set<pair<int,int>>st;
        vector<vector<int>>ans;
        st.insert({0,0});
      
       pq.push({nums1[0]+nums2[0],{0,0}});
       while(!pq.empty()){
           ans.push_back({nums1[pq.top().second.first],nums2[pq.top().second.second]});
          
           k--;
           if(k==0)return ans;
          
           int i=pq.top().second.first;
           int j=pq.top().second.second;
            pq.pop();

           if(i+1<nums1.size()&&st.find({i+1,j})==st.end()){
               pq.push({nums1[i+1]+nums2[j],{i+1,j}});
                st.insert({i+1,j});
           }
           if(j+1<nums2.size()&&st.find({i,j+1})==st.end()){
               pq.push({nums1[i]+nums2[j+1],{i,j+1}});
                st.insert({i,j+1});
           }



           
       }
       return ans;
        
    }
};