class Solution
{
    public:
        bool recursive(vector<int> &arr, int i,vector<int>&vis)
        {
            if (i >= arr.size() || i < 0||vis[i]==1)
            {
                      return   false;
               
            }
            if (arr[i] == 0)
            {
               
                return true;
            }
            
           vis[i]=1;
               bool left=     recursive(arr, i - arr[i],vis);
                   
             
             bool right=       recursive(arr, i + arr[i],vis);
             if(left||right)return true;
               

            return false;
        }
    bool canReach(vector<int> &arr, int start)
    {
        vector<int> vis(arr.size(), 0);
      
       return recursive(arr, start,vis);
        
    }
};