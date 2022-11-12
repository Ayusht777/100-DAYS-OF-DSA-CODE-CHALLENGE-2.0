
#include <bits/stdc++.h> 

using namespace std;
//Linear Sreach in an  Array using recursion
bool LinearSreach(int arr[],int size,int key){
  //base case
  if(size==0){
    return 0;
  }
  
  if(arr[0]==key){
   return true;
  }
  else{
    // if(arr[0]==key){
      // return true;
      LinearSreach(arr+1,size-1,key);
    // }
  }

  


}


int main(){
 int arr [5] {1,2,4,4,5};
 cout<<boolalpha;
 cout<<LinearSreach(arr,1,1);


}