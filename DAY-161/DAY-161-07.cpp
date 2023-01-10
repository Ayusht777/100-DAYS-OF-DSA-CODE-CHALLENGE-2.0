#include <bits/stdc++.h>
using namespace std;
//  Maximum sum of non-adjacent elements  (DP-SPACE OPTIMIZATION )
//Max Sum without Adjacents
//Stickler Thief
// https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=0

int solveDPSO(vector<int> &nums,int n){
    //RIGHT TO LEFT TRAVERSE
    int prev2 = 0;
    int prev1 = nums[0];
  for(int i = 1;i<n;i++){
    int incl = prev2 + nums[i];
    int excl = prev1 + 0;
    int curr =  max(incl,excl);
    prev2 = prev1;
    prev1 = curr;  
  }
    return prev1;
}
int maximumNonAdjacentSum(vector<int> &nums){
    int  n = nums.size();
    
    
 
    return solveDPSO(nums,n);
}