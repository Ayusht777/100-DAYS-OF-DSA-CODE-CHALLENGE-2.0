#include <bits/stdc++.h>
using namespace std;
//Build max heap (heapify)
void heapfiy(int * arr ,int  n ,int i){
    int largest = i; 
    int left = 2*i;
    int right = 2*i+1;
    
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
}

int main(){
   int arr[6] = {-1,54,53,55,52,50};
   int n = 5;
   for (size_t i = n/2; i > 0; i--)
   {
    heapfiy(arr,n,i);

   }
   cout<<"printing the array "<<endl;
   for(int i=1; i<=n;i++){
    cout<<arr[i]<<" ";


   }
   cout<<endl;
   

}
