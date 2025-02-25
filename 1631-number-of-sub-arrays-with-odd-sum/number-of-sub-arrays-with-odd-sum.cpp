class Solution {
public:
    int mod=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        int even=0,odd=0,subarray=0,e,o;
        
        for(int i=0;i<n;i++){
            if(arr[i]%2==0){
                e=(1+even)%mod;
                o=odd;
            }
            else{
                o=(1+even)%mod;
                e=odd;
            }
            
            even=e;
            odd=o;
            subarray= (subarray + odd)%mod;
        }
        return subarray;class Solution {
public:
vector<vector<int>>a;
void helper(vector<int>&arr,vector<int>&temp,int i){
    if(i==arr.size()){
        a.push_back(temp);
        return;
    }
    temp.push_back(arr[i]);
    helper(arr,temp,i+1);
    temp.pop_back();
    helper(arr,temp,i+1);
    return;

}
    int numOfSubarrays(vector<int>& arr) {
        vector<int>temp;
        helper(arr,temp,0);
        int count=0;
        for(int i=0;i<a.size();i++){
            int sum=0;
            for(int j=0;j<a[i].size();j++){
             cout<<a[i][j];
                sum=sum+a[i][j];
            }
            cout<<"-"<<sum<< " ";
            if(sum%2!=0){
               
                count++;
                cout<<"&&"<<count<<"&&";
            }
        }
        int mod=1e9+7;
        return count%mod;

        
    }
};
    }
};