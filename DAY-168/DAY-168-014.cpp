#include <bits/stdc++.h>
using namespace std;
//Longest Arithmetic Progression(Memorization)
//https://practice.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution{   
public:
    int solveMem(int index,int diff,int A[],unordered_map <int,int> dp []){
        //backward check
        if(index < 0){
            return 0;
        }
        if(dp[index].count(diff)){
            return dp[index][diff];
        }
        int ans =0;
        for(int j=index-1;j>=0;j--){
             if(A[index]-A[j] == diff){
                  ans = max(ans,1+solveMem(j,diff,A,dp));
             }
        }
        return dp[index][diff] = ans;
    }
    int lengthOfLongestAP(int A[], int n) {
        if(n<=2){
            return n;
        }
        unordered_map <int,int> dp[n+1];
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans = max(ans,2+solveMem(i,A[j]-A[i],A,dp));
                
            }
        }
        return ans;
    }
};