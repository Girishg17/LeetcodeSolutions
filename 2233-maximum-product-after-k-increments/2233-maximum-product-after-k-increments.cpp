class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
       priority_queue<long,vector<long>,greater<long>>pq;
       for(int i=0;i<nums.size();i++){
           pq.push(nums[i]);
       }
       while(k--){
           long top=pq.top();
           pq.pop();
           top=top+1;
           pq.push(top);
       }
      
       long  product=1;
       while(!pq.empty()){
           product=(product * pq.top())%1000000007;
           pq.pop();

       }
       return (product%1000000007);
        
    }
};