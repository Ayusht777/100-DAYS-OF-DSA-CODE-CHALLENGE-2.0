#include <bits/stdc++.h>
using namespace std;
//375. Guess Number Higher or Lower II
//https://leetcode.com/problems/guess-number-higher-or-lower-ii/

class Solution {
public:
    int solve(int start,int end){
        //base case
        if(start>=end){
            return 0;
        }
        int maxi =INT_MAX;
        for(int i =start;i<=end;i++){
            maxi = min(maxi,i + max(solve(start,i-1),solve(i+1,end)));
        }
        return maxi;
    }
    int getMoneyAmount(int n) {
        return solve(1,n);
    }
};