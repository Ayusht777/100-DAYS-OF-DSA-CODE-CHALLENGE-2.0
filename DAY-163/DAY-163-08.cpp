#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
//  Ninja And The Fence ( DP : Space Optimization )
// https://www.codingninjas.com/codestudio/problems/ninja-and-the-fence_3210208?leftPanelTab=0

int add(int a,int b){
    return (a%mod + b%mod)%mod;
}
int mul(int a,int b){
    //LONG LOGN INNT
    return (a%mod*1LL * b%mod)%mod;
}
int solveDPSO(int n, int k){
    
     
    int prev2 = k;
    
    int prev1 = add(k,mul(k,k-1));
        // k + k (k-1)
    for(int i =3 ;i<=n;i++){
    int ans  = add(mul(prev2,k-1) , mul(prev1,k-1));
    prev2 = prev1;
    prev1 = ans;    
    }
    return prev1;
}
int numberOfWays(int n, int k) {
   
    return solveDPSO(n,k);
}
