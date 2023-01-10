#include <bits/stdc++.h>
using namespace std;
//  Maximum sum of non-adjacent elements  (DP)
//Max Sum without Adjacents
//Stickler Thief
// https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=0
int solveDP(vector<int> &nums,int n,vector<int> &dp){
    //RIGHT TO LEFT TRAVERSE
    if( n < 0){
        return 0;
    }
    if(n ==  0){
        //singal element
        return nums[0];
    }
    //step2:
    if(dp[n] != -1){
        return dp[n];
    }
    int incl = solveDP(nums,n-2,dp) + nums[n];
    int excl = solveDP(nums,n-1,dp) + 0;
    dp[n] =  max(incl,excl);
    return dp[n];
}
int maximumNonAdjacentSum(vector<int> &nums){
    int  n = nums.size();
    //step 1 :
    vector<int> dp(n+1,-1);
    int ans = solveDP(nums,n-1,dp);
    return ans;
}