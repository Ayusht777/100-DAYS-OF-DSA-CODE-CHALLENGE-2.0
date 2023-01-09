#include <bits/stdc++.h>
using namespace std;
//  Nth Fibonacci Number  Using DP (Bottom - Down)
// https://www.codingninjas.com/codestudio/problems/nth-fibonacci-number_74156?leftPanelTab=0

int main()
{
    int n;
    cin>>n;
    //step 1:
    vector<int> dp(n+1,-1);
    //step 2:
    dp[0] = 0;
    dp[1] = 1;
    //step 3 :
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
        
    }
    cout<<dp[n]<<endl;
 
    
 } 