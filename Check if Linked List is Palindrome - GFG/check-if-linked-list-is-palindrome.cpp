//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool comparelist(Node * temp1,Node * temp2){
        if(temp1==NULL&&temp2==NULL)return true;
        if(temp1==NULL ||temp2==NULL)return false;
        while(temp1&&temp2){
            if(temp1->data!=temp2->data)return false;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        if(temp1)return false;
        if(temp2)return false;
        return true;
    }
    bool isPalindrome(Node *head)
    {
        //Your code here
        Node * slow=head;
        Node * fast=head;
        Node * prevs=NULL;
        if(head->next==NULL)return true;
        while(fast->next&&fast->next->next){
            prevs=slow;
            slow=slow->next;
            
            fast=fast->next->next;
        }
        if(fast->next==NULL){
            prevs->next=NULL;
        }
        Node * prev=NULL;
        Node * curr=slow->next;
        Node * follow=slow->next;
        slow->next=NULL;
        
      
        while(curr!=NULL){
            follow=follow->next;
            curr->next=prev;
            prev=curr;
            curr=follow;
        }
        
       return comparelist(head,prev);
        
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends