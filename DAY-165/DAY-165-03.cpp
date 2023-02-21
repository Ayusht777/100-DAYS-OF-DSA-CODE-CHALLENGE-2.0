#include <bits/stdc++.h>
using namespace std;
// Combination Sum IV (recusrion + Tabulation  ) 
// https://www.codingninjas.com/codestudio/problems/number-of-ways_3755252

int solveTab(vector<int> &num, int tar){
    //step 1 : create a dp array
    vector<int> dp(tar+1,0);
    dp[0] = 1;
    
    for(int i=1;i<=tar;i++){
        for(int j=0;j<num.size();j++){
          if (i - num[j] >= 0) {
            dp[i] = dp[i] + dp[i - num[j]];
          }
    }
    }
    
    return dp[tar];

}
int findWays(vector<int> &num, int tar)
{
    
    return solveTab(num,tar);
}