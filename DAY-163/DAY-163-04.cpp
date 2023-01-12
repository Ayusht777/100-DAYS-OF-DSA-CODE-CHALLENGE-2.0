#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
// Count derangements (DP : Space Optimization  )
// https://www.codingninjas.com/codestudio/problems/count-derangements_873861?leftPanelTab=0
long long int solveDPSO(int n){
    
    long long int prev2 = 0;
    long long int prev1 = 1;
    
    for(int i=3;i<=n;i++){
        long long int first = prev1 % mod;
        long long int second = prev2 % mod;
        long long int sum = (first + second) % mod;
        long long int ans = ((i-1) *sum )%mod;
        prev2 = prev1;
        prev1 = ans;
            
    }
    return prev1;
}
long long int countDerangements(int n) {
    
    return solveDPSO(n);
}