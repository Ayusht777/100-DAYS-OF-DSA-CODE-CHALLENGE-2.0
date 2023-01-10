#include <bits/stdc++.h>
using namespace std;
// Minimum Elements (DP)
// Number of Coins
//https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091
int solveDP(vector<int> &num, int target,vector<int> &dp){
    //base case
    if(target == 0){
        return 0;
    }
    if(target < 0){
        return INT_MAX;
    }
    //step 2
    if(dp[target] != -1){
        return dp[target];
    }
    int mini = INT_MAX;
    for(int i = 0;i<num.size();i++){
        int ans  = solveDP(num,target - num[i],dp);
        if(ans != INT_MAX){
            //mini ko update 
            mini = min(mini,ans+1);
        }
    }
    //step 3:
    dp[target] = mini;
    return mini;
}
int minimumElements(vector<int> &num, int x)
{
    //step  1:
    vector<int> dp(x+1,-1);
    int ans = solveDP(num,x,dp);
    if(ans == INT_MAX){
        return -1;
     }
    return ans;
}