#include <bits/stdc++.h>
using namespace std;
//Get Minimum Squares
// https://practice.geeksforgeeks.org/problems/get-minimum-squares0538/1


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