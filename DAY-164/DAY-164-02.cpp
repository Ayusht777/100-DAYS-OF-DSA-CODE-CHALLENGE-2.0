#include <bits/stdc++.h>
using namespace std;
// 0 1 Knapsack  Using Recusrion + Memorization 
// https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542?leftPanelTab=0

int solveMem(vector<int> &weight, vector<int>&value, int i, int capacity,vector<vector<int>> &dp){
  //base case
  //if only 1 item to steal ,the just compare the weight with knapsack 
  if(i == 0){
	  if(weight[0] <= capacity){
		  return value [0];
	  }
	  else
	  return 0;
  }
  if(dp[i][capacity] != -1){
    return dp[i][capacity];
  }
  int include = 0;
  if(weight[i] <= capacity){
	  include = value[i] + solveMem(weight,value,i-1,capacity - weight[i],dp);

  }
  int exclude =  0 + solveMem(weight,value,i-1,capacity,dp);
  dp[i][capacity] = max(exclude,include);
  return dp[i][capacity];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
  vector<vector<int>> dp(n,vector<int> (maxWeight+1,-1));

	return solveMem(weight,value,n-1,maxWeight,dp);
}
