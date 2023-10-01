class Solution {
public:
    string addBinary(string a, string b) {
    int carry=0;
    int i=a.size()-1;
    int j=b.size()-1;
    string ans;

    while(i>=0&&j>=0){
        int sum=(a[i]-'0')+(b[j]-'0')+carry;
        ans.push_back((sum%2)+'0');
        carry=sum/2;
        i--;
        j--;

      
    }
    while(i>=0){
        int sum=(a[i]-'0')+carry;
        ans.push_back((sum%2+'0'));
        carry=sum/2;
        i--;
    }

 while(j>=0){
        int sum=(b[j]-'0')+carry;
        ans.push_back((sum%2+'0'));
        carry=sum/2;
        j--;
    }  
    if(carry){
        ans.push_back('1');
    }  
     reverse(ans.begin(),ans.end());
     return ans;
        
    }
};