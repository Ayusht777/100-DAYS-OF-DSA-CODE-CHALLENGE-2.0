
#include <bits/stdc++.h> 

using namespace std;
//Sum of an Array using recursion


int sumofarr(int arr[],int size){

  //base case
   

  if(size==0){
    return 0;
  }
  if(size==1){
    return arr[0];
  }
 
   
 int  sum = arr[0]+sumofarr(arr+1,size-1);
  // cout<<sum<<endl;
  
    
    return sum;
  
}


int main(){
 int arr [5] {1,2,4,4,5};

 cout<<sumofarr(arr,5);

}