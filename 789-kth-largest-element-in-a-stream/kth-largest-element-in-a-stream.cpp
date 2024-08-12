class KthLargest {
public:
    priority_queue<int,vector<int>, greater<int>>pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int i=0;i<nums.size();i++){
            if(this->pq.size()>=k){
               this-> pq.push(nums[i]);
               this-> pq.pop();
        
            }
            else{
                this->pq.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        int ans;
        if(this->pq.size()>=k){
            this->pq.push(val);
            this->pq.pop();
            ans=this->pq.top();
        }
        else{
            this->pq.push(val);
            ans=this->pq.top();
        }
        return ans;
         

    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */