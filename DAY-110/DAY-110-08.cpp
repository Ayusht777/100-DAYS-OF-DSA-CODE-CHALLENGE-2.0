
#include <bits/stdc++.h> 

using namespace std;
//Bubble Sort using Recursion

void SortArray(int arr[],int n){
  //base case
  if(n==0||n==1){
    return;
  }
  for(int i =0;i<n-1;i++){
    if(arr[i]>arr[i+1]){
      swap(arr[i],arr[i+1]);
    }
  }
  SortArray(arr,n-1);
}

  




int main(){
  int arr [5] {0,8,9,1,4};
  cout<<"Array "<<endl;
  for(int i=0;i<5;i++){
    cout<<arr[i]<<" ";
  }
  SortArray(arr,5);
  cout<<endl;
   for(int i=0;i<5;i++){
    cout<<arr[i]<<" ";
  }




  
 
 
 


}