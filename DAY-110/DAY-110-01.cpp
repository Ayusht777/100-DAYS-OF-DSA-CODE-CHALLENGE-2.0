
#include <bits/stdc++.h> 

using namespace std;
//Check If an Array Is Sorted Or not using recursion


bool isSorted(int arr[],int size){
  //base case
  if(size==0||size==1){
    return true;
  }
  if(arr[0]>arr[1]){
    return false;
  }

  //recursive calling

   return (isSorted(arr+1,size-1));


}


int main(){
 int arr [5] {1,2,4,4,5};
 
 cout<<boolalpha;
 cout<<isSorted(arr,5);

}