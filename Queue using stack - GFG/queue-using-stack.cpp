//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Queue {
    stack<int> output;
public:

    void enqueue(int x) {
        output.push(x);
    }

    int dequeue() {
        stack<int>temp;
        
        while(!output.empty()){
            temp.push(output.top());
            output.pop();
            
        }
        if(temp.empty())return -1;
        int ele=temp.top();
        temp.pop();
        while(!temp.empty()){
            output.push(temp.top());
            temp.pop();
            
        }
        return  ele;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Queue ob;

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            ob.enqueue(a);
        }
        else if(QueryType==2)
        {
            cout<<ob.dequeue()<<" ";

        }
        }
    cout<<endl;
    }
}

// } Driver Code Ends