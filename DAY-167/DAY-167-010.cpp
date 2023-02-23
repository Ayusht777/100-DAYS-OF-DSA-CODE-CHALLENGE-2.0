#include <bits/stdc++.h>
using namespace std;
// Longest Increasing Subsequence (Memorization)
// https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

class Solution
{
    public:
    int solveMem(int n,int a[],int curr,int prev,vector<vector<int>> &dp){
        //base case
        if(curr == n){
            return 0;
        }
        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }
        //include call
        int take =0;
        if(prev == -1 || a[prev] <a[curr])
           take = 1 + solveMem(n,a,curr+1,curr,dp);
        //exclude
        int notTake = 0;
        notTake = 0 + solveMem(n,a,curr+1,prev,dp);
        
        dp[curr][prev+1] = max(take,notTake);
        return dp[curr][prev+1];
        
        
    }
    int longestSubsequence(int n, int a[])
    {
       vector<vector<int>> dp(n,vector<int>(n+1,-1));
       return solveMem(n,a,0,-1,dp);
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