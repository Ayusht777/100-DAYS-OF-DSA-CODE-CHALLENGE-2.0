#include <bits/stdc++.h>
using namespace std;
// K-th Largest Sum Subarray (Heap)
// https://www.codingninjas.com/codestudio/problems/k-th-largest-sum-contiguous-subarray_920398?leftPanelTab=0


int getKthLargest(vector<int> &arr, int k)
{   //min heap
	priority_queue<int , vector<int> ,greater<int>> q;
    int n = arr.size();
    for(int i=0;i<n;i++){
        int sum =0;
        for(int j =i ;j<n;j++){
            sum = sum +arr[j];
            if(q.size() < k){
                q.push(sum);
            }
            else if(sum > q.top()){
                q.pop();
                q.push(sum);
            }
        }
    }
    
    return ( q.top() );
}
