class Solution {
public:
    string decodeAtIndex(string s, int k) {
       long long size=0;
       for(int i=0;i<s.size();i++){
           if(s[i]>='2'&&s[i]<='9'){
               size=size*(s[i]-'0');

           }
           else{
               size++;
           }
       }
    

      for(int i=s.size()-1;i>=0;i--){
          k=k%size;
           if(k==0&&s[i]>='a'&&s[i]<='z')return string(1,s[i]);
          
          if(s[i]>='2'&&s[i]<='9'){
              size=size/(s[i]-'0');
           }
           else{
               size--;
           }
          

          
        

      }
      return "";
        
    }
};