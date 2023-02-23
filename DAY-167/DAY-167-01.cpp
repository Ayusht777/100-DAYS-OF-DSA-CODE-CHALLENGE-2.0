#include <bits/stdc++.h>
using namespace std;
//1824. Minimum Sideway Jumps

///https://leetcode.com/problems/minimum-sideway-jumps/

class Solution {
public:
    int solve(vector<int>& obstacles,int currlane,int currpos){
        //base
        int n = obstacles.size()-1; 
        if(currpos == n){
            return 0;
        }
        if(obstacles[currpos+1] !=  currlane){
            return solve(obstacles,currlane,currpos+1);
        }
        else{
            //sideways jumps
            int ans = INT_MAX;
            for(int i=1;i<=3;i++){
                if(currlane != i && obstacles[currpos] != i){
                    ans = min(ans,1+ solve(obstacles,i,currpos));
                }
            }
            return ans;
        }

    }
    int minSideJumps(vector<int>& obstacles) {
        return solve(obstacles,2,0);
    }
};