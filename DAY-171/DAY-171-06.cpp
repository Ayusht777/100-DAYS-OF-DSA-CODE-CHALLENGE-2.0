#include <bits/stdc++.h>
using namespace std;
//72. Edit Distance
//https://leetcode.com/problems/edit-distance/
class Solution {
public:
    int solve(string &a ,string &b,int i,int j){
        //base case
        if(i == a.length()){
            return b.length()-j;
        }
        if(j == b.length()){
            return a.length()-i;
        }
        int ans = 0;
        if(a[i] == b[j]){
            return solve(a,b,i+1,j+1);
        }
        else{
            //inseert
            int insertAns = 1 + solve(a,b,i,j+1);
            int deleteAns = 1 +solve(a,b,i+1,j);
            int replaceAns = 1  +solve(a,b,i+1,j+1);
            ans  = min(insertAns,min(deleteAns,replaceAns));
        }
        return ans;

    }
    int minDistance(string word1, string word2) {
        return solve(word1,word2,0,0);
    }
};