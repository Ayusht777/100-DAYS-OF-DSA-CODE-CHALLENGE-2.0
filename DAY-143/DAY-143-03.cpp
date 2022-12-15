#include <bits/stdc++.h>
using namespace std;
//Minimum Cost of ropes
//https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // min heap
        priority_queue<long long ,vector<long long>,greater<long long>> q;
        for(int i=0;i<n;i++){
            q.push(arr[i]);
        }
        
        long long  cost =0;
        while(q.size() > 1){
              long long  a = q.top();
              q.pop();
              long long b =q.top();
              q.pop();
              
              long long sum = a + b;
              cost += sum;
              
              q.push(sum);
        }
        return cost;
    
    }
};
