#include <bits/stdc++.h>
using namespace std;
// Build Heap 
//https://www.codingninjas.com/codestudio/problems/build-heap_975375?leftPanelTab=0

void heapfiy(vector<int> &arr ,int  n ,int i){
    int largest = i; 
    int left = 2*i+1;//given
    int right = 2*i+2;
    
    if(left < n && arr[largest] < arr[left]){
        largest =left;
    }
    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest] ,arr[i]);
        heapfiy(arr,n,largest);
    }
    return;
}
vector<int> buildHeap(vector<int> arr, int n)
{	
     for (int i = n/2-1; i >= 0; i--)
     {
       heapfiy(arr,n,i);

     }
    return arr;
}