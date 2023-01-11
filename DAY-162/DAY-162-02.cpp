#include <bits/stdc++.h>
using namespace std;
//  Cut Into Segments (Recursion)
// https://www.codingninjas.com/codestudio/problems/cut-into-segments_1214651?leftPanelTab=0
int solve(int n, int x, int y, int z){
    //base case
    if(n==0){
        return 0;
    }
    if(n < 0){
        return INT_MIN;
        //- ve infinity
    }
    
    int a = solve(n-x,x,y,z) + 1;
    int b = solve(n-y,x,y,z) + 1;
    int c = solve(n-z,x,y,z) + 1;
    return max(a,max(b,c));
}
int cutSegments(int n, int x, int y, int z) {
	int ans = solve(n,x,y,z);
    
    if(ans < 0){
        return 0;
        //no possible solution
    }
    return ans;
}