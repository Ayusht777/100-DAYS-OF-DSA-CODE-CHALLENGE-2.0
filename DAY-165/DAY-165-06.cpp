#include <bits/stdc++.h>
using namespace std;
//Get Minimum Squares (Recusrion + TAB)
// https://practice.geeksforgeeks.org/problems/get-minimum-squares0538/1

class Solution{
	public:
	int solveTab(int n){
	    //base case
	    vector<int> dp(n+1,INT_MAX);
	    dp[0] = 0;
	    for(int i=1;i<=n;i++){
	        for(int j=1;j*j<=n;j++){
	        
	        int sq = j*j;
	        
	        if(i-sq>=0){
	        
	        dp[i] = min(dp[i],dp[i-sq]+1);
	        
	            
	        }
	        }
	 }
	    return dp[n];
	    
	}
	int MinSquares(int n)
	{
	    
	    return solveTab(n);
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