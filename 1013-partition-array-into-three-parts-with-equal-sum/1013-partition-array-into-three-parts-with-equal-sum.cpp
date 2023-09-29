class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
      
    if(sum%3!=0)return false;
    int count=0;
    int s=0;
    for(int i=0;i<arr.size();i++){
        s+=arr[i];
        if(sum/3==s){
            count++;
            s=0;
            if(count==3)return true;
        }


    }
    // if(count>=3)return true;
    return false;


        
    }
};