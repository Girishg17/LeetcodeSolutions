class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>arr;
        
        int j=0;
        int i=1;
        while(i<=n && j<target.size()){
            if(target[j]==i){
                arr.push_back("Push");
                j++;
                i++;
            }
            else{
                while(i<target[j]){
                    arr.push_back("Push");
                    arr.push_back("Pop");
                    i++;
                }
            }


            

        }
        return arr;
            

            
        
        
    }
};