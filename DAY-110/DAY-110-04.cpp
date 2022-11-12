
#include <bits/stdc++.h> 

using namespace std;
//Binary Sreach in an  Array using recursion
bool BinarySreach(int arr[],int s,int e,int key){
  //base case
  if(s>e){
    return false;
  }
  int mid = s+(e-s)/2;
  if(arr[mid]==key){
    return true;
  }
  if(arr[mid]<key){
    return (BinarySreach(arr,mid+1,e,key));
    
  }
  else{
    return(BinarySreach(arr,s,mid-1,key));
  }

  }

  




int main(){
 int arr [5] {1,2,4,4,5};
 cout<<boolalpha;
 cout<<BinarySreach(arr,0,5,4);
 


}