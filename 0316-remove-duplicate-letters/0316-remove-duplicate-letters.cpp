class Solution {
public:
    // string maxi="z";
    // void solve(string &s,int i,int n,vector<int>a,string &temp){
    //     if(temp.size()==n){
    //         maxi=min(maxi,temp);
    //         return;
    //     }

    //     if(i>=s.size())return;
    //     if(a[s[i]-'a']==0){
    //         temp.push_back(s[i]);
    //         a[s[i]-'a']++;
    //         solve(s,i+1,n,a,temp);
    //         a[s[i]-'a']--;
    //         temp.pop_back();
    //     }
    //     solve(s,i+1,n,a,temp);

    // }
    string removeDuplicateLetters(string s) {
        // vector<int>arr(26,0);
        // string ans="";
        // for(int i=0;i<s.size();i++){
        //     if(arr[s[i]-'a']==0){
        //         ans+=s[i];
        //         arr[s[i]-'a']++;
        //     }
        // }
        // vector<int>a(26,0);
        // string temp="";
        // solve(s,0,ans.size(),a,temp);
        // return maxi;
        stack<char>st;
        vector<int>arr(26,0);
        vector<int>seen(26,0);
        for(int i=0;i<s.size();i++){
            arr[s[i]-'a']++;
        }
        for(int i=0;i<s.size();i++){
            if(seen[s[i]-'a']){
                 arr[s[i]-'a']--;
                 continue;

            }
            
            while(!st.empty()&&st.top()>s[i]&&arr[st.top()-'a']>0){
                
                // arr[st.top()-'a']++;
                seen[st.top()-'a']=0;
               
                st.pop();

            }
            st.push(s[i]);
            arr[s[i]-'a']--;
            seen[s[i]-'a']=1;


        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

        


        
    }
};