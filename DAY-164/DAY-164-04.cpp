#include <bits/stdc++.h>
using namespace std;
// 0 1 Knapsack  Using Recusrion + Tab (space optimaztion)
// https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542?leftPanelTab=0
int solveTab(vector<int> &weight, vector<int>&value, int n, int capacity){
  //step 1 :
  vector<int> prev(capacity+1,0);
  vector<int> curr (capacity+1,0);

  //step 2 :
  for(int w =weight[0];w<=capacity;w++){
    if(weight[0]<=capacity){
      prev[w] = value[0];
    }
    else{
      prev[w] = 0;
    }
  }

  for(int i=1;i<n;i++){
    for(int w=0;w<=capacity;w++){
      int include = 0;
      if (weight[i] <= w) {
        include = value[i] + prev[w-weight[i]];
      }
      int exclude = 0 + prev[w];

      curr[w] = max(exclude, include);
    }
    prev= curr;
  }
  
  return prev[capacity];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
  

	return solveTab(weight,value,n,maxWeight);
}