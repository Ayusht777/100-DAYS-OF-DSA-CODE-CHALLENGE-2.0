#include <bits/stdc++.h>
using namespace std;
//Longest Arithmetic Progression(Tabulation)
//https://practice.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        if(n<=2){
            return n;
        }
        int ans = 0;
        unordered_map<int,int> dp[n+1];
        
        for(int i = 1;i<n;i++){
            for(int j=0;j<i;j++){
                int diff = A[i]-A[j];
                int cnt = 1;
                //check if anwser already present
                if(dp[j].count(diff)){
                    cnt  = dp[j][diff];
                }
                dp[i][diff] = 1 + cnt;
                ans = max (ans,dp[i][diff]);
            }
        }
        return ans;
    }
};