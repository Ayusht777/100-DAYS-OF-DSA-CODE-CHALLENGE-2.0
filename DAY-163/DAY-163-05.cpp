#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
//  Ninja And The Fence ( Recursion )
// https://www.codingninjas.com/codestudio/problems/ninja-and-the-fence_3210208?leftPanelTab=0

int add(int a,int b){
    return (a%mod + b%mod)%mod;
}
int mul(int a,int b){
    return (a%mod * b%mod)%mod;
}
int solve(int n, int k){
    //base case
    if(n==1){
        return k;
        //no of paints
    }
    if(n == 2){
        return add(k,mul(k,k-1));
        // k + k (k-1)
    }
    int ans  = add(mul(solve(n-2,k),k-1) , mul(solve(n-1,k),k-1));
    return ans;
}
int numberOfWays(int n, int k) {
    return solve(n,k);
}
