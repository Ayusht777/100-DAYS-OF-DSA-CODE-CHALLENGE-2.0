#include <bits/stdc++.h>
using namespace std;
// Minimum Elements (DP-TABULATION)
// Number of Coins
//https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091
int solveDPTab(vector<int> &num, int target){
    vector<int> dp(target+1,INT_MAX);
    dp[0] = 0;
    for(int i=1;i<=target;i++){
        // trying to solve every amount to figure  form 1 to x
        for(int j=0;j<num.size();j++){
            if(i-num[j] >= 0 && dp[i-num[j]] !=INT_MAX){
                dp[i] = min(dp[i],dp[i-num[j]] + 1);
            }
        }
    }
    if(dp[target]==INT_MAX){
        return -1;
    }
    return dp[target];
}
int minimumElements(vector<int> &num, int x)
{
    
    return solveDPTab(num,x); 
}