#include <bits/stdc++.h>
using namespace std;
// 0 1 Knapsack 
// https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542?leftPanelTab=0
int solve(vector<int> &weight, vector<int>&value, int i, int capacity){
  //base case
  //if only 1 item to steal ,the just compare the weight with knapsack 
  if(i == 0){
	  if(weight[0] <= capacity){
		  return value [0];
	  }
	  else
	  return 0;
  }
  int include = 0;
  if(weight[i] <= capacity){
	  include = value[i] + solve(weight,value,i-1,capacity - weight[i]);

  }
  int exclude =  0 + solve(weight,value,i-1,capacity);
  int ans = max(exclude,include);
  return ans;
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return solve(weight,value,n,maxWeight);
}