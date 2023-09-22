class Solution {
public:
   bool check(string s,string &b){
       int j=0;
       for(int i=0;i<s.size();i++){
          
          if(s[i]==b[0]){
              
              int j=0;
              int y=i;
              while(y<s.size()&&s[y]==b[j]){
                  
                  j++;
                  y++;
              }
              cout<<j<<endl;
              if(j>=b.size())return true;
          }
       }
       return false;
   }
    int repeatedStringMatch(string a, string b) {
        int asize=a.size();
        int bsize=b.size();
        string tp=a;
        int ans=1;
        while(a.size()<b.size()){
            a+=tp;
            ans++;


        }
       
        if(check(a,b))return ans;
        if(check (a+tp,b))return ans+1;
        return -1;
        
    }
};