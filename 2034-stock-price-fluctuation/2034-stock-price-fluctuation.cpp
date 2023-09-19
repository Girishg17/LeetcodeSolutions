class StockPrice {
public:
    StockPrice() {
        
    }
    int latest=0;
    unordered_map<int,int>mp;
    multiset<int>st;
    int time=0;
    void update(int timestamp, int price) {
        if(timestamp>=time){
            latest=price;
            time=timestamp;
        }
        if(mp.find(timestamp)==mp.end()){
            mp[timestamp]=price;
            st.insert(price);
        }
        else{
            auto it=st.find(mp[timestamp]);
            
              st.erase(it);
             mp[timestamp]=price;
            st.insert(price);
        }
        
        
    }
    
    int current() {
        return latest;
        
    }
    
    int maximum() {
        return *(st.rbegin());
        
    }
    
    int minimum() {
        return *(st.begin());
        
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */