#include <bits/stdc++.h>
using namespace std;
//  Maximum sum of non-adjacent elements  (RECURSION)
// https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=0


int solve(vector<int> &nums,int n){
    //RIGHT TO LEFT TRAVERSE
    if( n < 0){
        return 0;
    }
    if(n ==  0){
        //singal element
        return nums[0];
    }
    int incl = solve(nums,n-2) + nums[n];
    int excl = solve(nums,n-1) + 0;
    
    return max(incl,excl);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int  n = nums.size();
    int ans = solve(nums,n-1);
    return ans;
}

