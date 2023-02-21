#include <bits/stdc++.h>
using namespace std;
//Get Minimum Squares (Recusrion + Memorization)
// https://practice.geeksforgeeks.org/problems/get-minimum-squares0538/1

class Solution{
	public:
	int solveMem(int n,vector<int> &dp){
	    //base case
	    if(n==0){
	        return 0;
	    }
	    if(dp[n] != -1){
	        return dp[n];
	    }
	    int ans = n;
	    for(int i=1;i*i<=n;i++){
	        int sq = i*i;
	        ans = min(ans,solveMem(n-sq,dp)+1);
	    }
	    dp[n] =ans;
	    return dp[n];
	}
	int MinSquares(int n)
	{
	    vector<int> dp(n+1,-1);
	    return solveMem(n,dp);
	}
};

class Solution{
	public:
	int solve(int n){
	    //base case
	    if(n==0){
	        return 0;
	    }
	    int ans = n;
	    for(int i=1;i*i<=n;i++){
	        int sq = i*i;
	        ans = min(ans,solve(n-sq)+1);
	    }
	    return ans;
	}
	int MinSquares(int n)
	{
	    return solve(n);
	}
};