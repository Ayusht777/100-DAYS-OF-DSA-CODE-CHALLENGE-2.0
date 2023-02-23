#include <bits/stdc++.h>
using namespace std;
// Longest Increasing Subsequence (SO)
// https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

class Solution
{
    public:
    int solveSO(int n,int a[]){
        
       vector<int> currRow (n+1,0);
       vector<int> nextRow (n+1,0);
       for(int curr = n-1;curr>=0;curr--){
           for(int prev =curr-1;prev>=-1;prev--){
               
              //include call
              int take =0;
              if(prev == -1 || a[prev] <a[curr])
                take = 1 + nextRow[curr+1];
              //exclude
               int notTake = 0;
              notTake = 0 + nextRow[prev+1];
        
              currRow[prev+1] = max(take,notTake);
              
           }
           nextRow  = currRow;
       }
       return nextRow[0];
        
        
    }
    int longestSubsequence(int n, int a[])
    {
       
       return solveSO(n,a);
    }
};
//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends