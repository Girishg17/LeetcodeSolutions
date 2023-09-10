class Solution {
public:

    int countOrders(int n) {
        long MOD = 1e9+7;
        vector<long>arr(n+1);
        arr[0]=0;
        arr[1]=1;
        for(int i=2;i<=n;i++){
            int m=2*(i-1)+1;
            int sum = (m*(m+1))/2;
            arr[i]=(arr[i-1]*sum)%(MOD);
        }
        return (int)arr[n];
        
    }
};