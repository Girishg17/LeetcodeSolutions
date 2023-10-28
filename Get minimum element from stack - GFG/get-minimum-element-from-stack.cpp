//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    stack<pair<int,int>>st;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           if(st.empty())return -1;
           return st.top().second;
           //Write your code here
       }
       
       /*returns poped element from stack*/
       int pop(){
           if(st.empty())return -1;
           int temp=st.top().first;
           st.pop();
           return temp;
           //Write your code here
       }
       
       /*push element x into the stack*/
       void push(int x){
           
          if(st.empty())st.push({x,x});
          else{
              st.push({x,min(x,st.top().second)});
          }
           //Write your code here
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends