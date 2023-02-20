#include <bits/stdc++.h>
using namespace std;
// 0 1 Knapsack  Using Recusrion + Tab
// https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542?leftPanelTab=0
int solveTab(vector<int> &weight, vector<int>&value, int n, int capacity){
  //step 1 :
  vector<vector<int>> dp(n,vector<int> (capacity+1,0));
  //step 2 :
  for(int w =weight[0];w<=capacity;w++){
    if(weight[0]<=capacity){
      dp[0][w] = value[0];
    }
    else{
      dp[0][w] = 0;
    }
  }

  for(int i=1;i<n;i++){
    for(int w=0;w<=capacity;w++){
      int include = 0;
      if (weight[i] <= w) {
        include = value[i] + dp[i - 1][w - weight[i]];
      }
      int exclude = 0 + dp[i - 1][w];

      dp[i][w] = max(exclude, include);
    }
  }
  return dp[n-1][capacity];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
  

	return solveTab(weight,value,n,maxWeight);
}