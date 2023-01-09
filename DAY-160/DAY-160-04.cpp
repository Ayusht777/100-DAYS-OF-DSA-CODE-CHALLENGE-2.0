#include <bits/stdc++.h>
using namespace std;
// Count Ways To Reach The N-th Stairs  using Recursion (TLE)
//https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650?leftPanelTab=0
#define MOD 1000000007;
int solve(long long int nStairs,int i){
    //base case
    if( i == nStairs){
        return 1; //mtlab ki distance == source
    }
    if(i > nStairs){
        return 0;
    }
    return (solve(nStairs,i+1) + solve(nStairs,i+2)) % MOD;
}
int countDistinctWays(int nStairs) {
   int ans = solve(nStairs,0);
   return ans; 
}