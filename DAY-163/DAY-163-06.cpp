#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
//  Ninja And The Fence ( DP : Recursion + Memorization  )
// https://www.codingninjas.com/codestudio/problems/ninja-and-the-fence_3210208?leftPanelTab=0

int add(int a,int b){
    return (a%mod + b%mod)%mod;
}
int mul(int a,int b){
    //LONG LOGN INNT
    return (a%mod*1LL * b%mod)%mod;
}
int solveDP(int n, int k,vector<int> &dp){
    //base case
    if(n==1){
        return k;
        //no of paints
    }
    if(n == 2){
        return add(k,mul(k,k-1));
        // k + k (k-1)
    }
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n]  = add(mul(solveDP(n-2,k,dp),k-1) , mul(solveDP(n-1,k,dp),k-1));
    return dp[n];
}
int numberOfWays(int n, int k) {
    vector<int> dp(n+1,-1);
    return solveDP(n,k,dp);
}
