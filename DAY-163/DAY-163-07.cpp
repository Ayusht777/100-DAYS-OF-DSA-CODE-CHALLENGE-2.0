#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
//  Ninja And The Fence ( DP : Tabulation  )
// https://www.codingninjas.com/codestudio/problems/ninja-and-the-fence_3210208?leftPanelTab=0

int add(int a,int b){
    return (a%mod + b%mod)%mod;
}
int mul(int a,int b){
    //LONG LONG INT
    return (a%mod*1LL * b%mod)%mod;
}
int solveDPTab(int n, int k){
    vector<int> dp(n+1,0);
     
    dp[1] = k;
    
    dp[2] = add(k,mul(k,k-1));
        // k + k (k-1)
    for(int i =3 ;i<=n;i++){
    dp[i]  = add(mul(dp[i-2],k-1) , mul(dp[i-1],k-1));
    }
    return dp[n];
}
int numberOfWays(int n, int k) {
   
    return solveDPTab(n,k);
}
