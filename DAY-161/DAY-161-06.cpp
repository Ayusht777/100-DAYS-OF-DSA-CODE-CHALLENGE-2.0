#include <bits/stdc++.h>
using namespace std;
//  Maximum sum of non-adjacent elements  (DP-TABULATION)
//Max Sum without Adjacents
//Stickler Thief
// https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=0

int solveDP(vector<int> &nums,int n){
    //RIGHT TO LEFT TRAVERSE
    vector<int> dp(n,0);
    //base case
    dp[0] = nums[0];
  for(int i = 1;i<n;i++){
    int incl = dp[i-2] + nums[i];
    int excl = dp[i-1] + 0;
    dp[i] =  max(incl,excl);
  }
    return dp[n-1];
}
int maximumNonAdjacentSum(vector<int> &nums){
    int  n = nums.size();
    
    
 
    return solveDP(nums,n);
}