#include <bits/stdc++.h>
using namespace std;
// Combination Sum IV (recusrion + Memorization ) 
// https://www.codingninjas.com/codestudio/problems/number-of-ways_3755252

int solveMem(vector<int> &num, int tar,vector<int> &dp){
    //base case
    if(tar == 0){
        return 1;
    }
    if(tar <0){
      return 0;
    }
    if(dp[tar] != - 1){
        return dp[tar];
    }

    int ans = 0;
    for(int i=0;i<num.size();i++){
        ans = ans + solveMem(num,tar-num[i],dp);
    }
    dp[tar] = ans; 
    return dp[tar];


}
int findWays(vector<int> &num, int tar)
{
    //step 1 : create a dp array
    vector<int> dp(tar+1,-1);
    return solveMem(num,tar,dp);
}