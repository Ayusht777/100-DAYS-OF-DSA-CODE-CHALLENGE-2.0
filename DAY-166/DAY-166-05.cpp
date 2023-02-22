#include <bits/stdc++.h>
using namespace std;
//1039. Minimum Score Triangulation of Polygon(Recursion)

//https://leetcode.com/problems/minimum-score-triangulation-of-polygon/

class Solution {
public:
    int solve(vector<int>& v,int i,int j){
        //base case
        if(i+1 == j){
            //2 value line
            return 0;
        }
        int ans = INT_MAX;
        for(int k = i+1;k<j;k++){
            ans  = min(ans,v[i]*v[j]*v[k] + solve(v,i,k)+solve(v,k,j) );
        }
        return ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        return solve(values,0,n-1);
        
    }
};