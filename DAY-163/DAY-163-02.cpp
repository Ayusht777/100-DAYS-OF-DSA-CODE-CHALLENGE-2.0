#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
// Count derangements (DP : Recursion + Memorization )
// https://www.codingninjas.com/codestudio/problems/count-derangements_873861?leftPanelTab=0
long long int solveDP(int n,vector<long long int> &dp){
    //base case
    if(n == 1){
        //ki arr ma ek hi element ha 0 
        return 0;
    }
    if(n == 2){
        return 1;
        //arr [0,1] so possible de-arrangement  1
    }
    if(dp[n] != -1){
        return dp[n];
    }
    
    dp[n] = (n-1)%mod * ((solveDP(n-1,dp))%mod + (solveDP(n-2,dp))%mod)%mod;
    
    return dp[n];
}
long long int countDerangements(int n) {
    vector<long long int> dp(n+1,-1);
    return solveDP(n,dp);
}