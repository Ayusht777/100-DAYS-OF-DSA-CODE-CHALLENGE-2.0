#include <bits/stdc++.h>
using namespace std;
//  Cut Into Segments (DP : Recursion + Memorization)
// Maximize The Cut Segments
// https://www.codingninjas.com/codestudio/problems/cut-into-segments_1214651?leftPanelTab=0
int solveDP(int n, int x, int y, int z, vector<int> &dp){
    //base case
    if(n==0){
        return 0;
    }
    if(n < 0){
        return INT_MIN;
        //- ve infifnty
    }
    //step 2 :
    if(dp[n] != - 1){
        return dp[n];
    }
    int a = solveDP(n-x,x,y,z,dp) + 1;
    int b = solveDP(n-y,x,y,z,dp) + 1;
    int c = solveDP(n-z,x,y,z,dp) + 1;
    dp[n] = max(a,max(b,c)); //call save kara 
    return dp[n];
}
int cutSegments(int n, int x, int y, int z) {
	//STEP 1 :
    vector<int> dp(n+1,-1);
    int ans = solveDP(n,x,y,z,dp);
    if(ans < 0){
        return 0;
        //no possible solution
    }
    return ans;
}