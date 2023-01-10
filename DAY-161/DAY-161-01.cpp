#include <bits/stdc++.h>
using namespace std;
// Minimum Elements (RECURSION -TLE)
//https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091
int solveRecursion(vector<int> &num, int target){
    //base case
    if(target == 0){
        return 0;
    }
    if(target < 0){
        return INT_MAX;
    }
    int mini = INT_MAX;
    for(int i = 0;i<num.size();i++){
        int ans  = solveRecursion(num,target - num[i]);
        if(ans != INT_MAX){
            //mini ko update 
            mini = min(mini,ans+1);
        }
    }
    return mini;
}
int minimumElements(vector<int> &num, int x)
{
    int ans = solveRecursion(num,x);
    if(ans == INT_MAX){
        return -1;
     }
    return ans;
}