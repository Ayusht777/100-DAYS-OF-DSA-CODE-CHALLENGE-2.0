#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
// Count derangements ( Recursion )
// https://www.codingninjas.com/codestudio/problems/count-derangements_873861?leftPanelTab=0

long long int countDerangements(int n) {
    //base case
    if(n == 1){
        //ki arr ma ek hi element ha 0 
        return 0;
    }
    if(n == 2){
        return 1;
        //arr [0,1] so possible de-arrangement  1
    }
    
    long long int ans = ( (n-1)% MOD * (countDerangements(n-1)% MOD + countDerangements(n-2)% MOD) );
    
    return ans;
}