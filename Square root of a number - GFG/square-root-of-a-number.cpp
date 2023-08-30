//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here 
        if(x==0)return 0;
        if(x==1)return 1;
        long long int high=x;
        long long int start=1;
        while(start<=high){
            long long int mid=start+(high-start)/2;
            if(floor(mid*mid)<=x &&floor((mid+1)*(mid+1))>x)return mid;
            if(floor(mid*mid)>x){
                high=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends