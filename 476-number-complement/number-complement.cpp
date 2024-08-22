class Solution {
public:
    int findComplement(int num) {
        string s;
        while(num != 0 ){
            if(num%2==0)  s = '1'+s;
            else  s = '0'+s;

            num = num/2;
        }
        int ans=0;
        int p=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='1') ans += pow(2,p);
            p++;
        }
        return ans;
    }
};