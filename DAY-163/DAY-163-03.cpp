#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
// Count derangements (DP : Tabulation )
// https://www.codingninjas.com/codestudio/problems/count-derangements_873861?leftPanelTab=0
long long int solveDPTab(int n){
    vector<long long int> dp(n+1,0);
    dp[1] = 0;
    dp[2] = 1;
    
    for(int i=3;i<=n;i++){
        long long int first = dp[i-1] % mod;
        long long int second = dp[i-2] % mod;
        long long int sum = (first + second) % mod;
        long long int ans = ((i-1) *sum )%mod;
        dp[i] = ans;
    }
    return dp[n];
}
long long int countDerangements(int n) {
    
    return solveDPTab(n);
}