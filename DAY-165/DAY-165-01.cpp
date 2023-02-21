#include <bits/stdc++.h>
using namespace std;
// Combination Sum IV (recusrion) 
// https://www.codingninjas.com/codestudio/problems/number-of-ways_3755252
int solve(vector<int> &num, int tar){
    //base case
    if(tar == 0){
        return 1;
    }
    if(tar <0){
      return 0;
    }

    int ans = 0;
    for(int i=0;i<num.size();i++){
        ans = ans + solve(num,tar-num[i]);
    } 
    return ans;


}
int findWays(vector<int> &num, int tar)
{
    return solve(num,tar);
}