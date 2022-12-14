#include <bits/stdc++.h>
using namespace std;
//  Build Min Heap 
//https://www.codingninjas.com/codestudio/problems/build-min-heap_1171167?leftPanelTab=0
void heapfiy(vector<int> &arr ,int  n ,int i){
    int smallest = i; 
    int left = 2*i+1;//given
    int right = 2*i+2;
    
    if(left < n && arr[smallest] > arr[left]){
        smallest =left;
    }
    if(right < n && arr[smallest] > arr[right]){
        smallest = right;
    }

    if(smallest != i){
        swap(arr[smallest] ,arr[i]);
        heapfiy(arr,n,smallest);
    }
    return;
}
vector<int> buildMinHeap(vector<int> &arr)
{
    for (int i = arr.size()/2-1; i >= 0; i--)
     {
       heapfiy(arr,arr.size(),i);

     }
    return arr;
}
