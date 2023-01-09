#include <bits/stdc++.h>
using namespace std;
//  Nth Fibonacci Number  Using DP (Top - Down)
// https://www.codingninjas.com/codestudio/problems/nth-fibonacci-number_74156?leftPanelTab=0

int fib(int n,vector<int> &dp){
    if(n <=  1){
        return n;
    }
    if(dp[n] != -1){
      return dp[n]; //store function calls  
    }
    dp[n] = fib(n-1,dp) +  fib(n-2,dp);
    return dp[n];
}
int main()
{   int n;
    cin>>n;
    //step 1 : 
    vector<int> dp (n+1,-1);
    cout<<fib(n,dp)<<endl;
    return 0;
}