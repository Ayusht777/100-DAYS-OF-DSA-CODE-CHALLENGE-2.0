#include<iostream>
#include <bits/stdc++.h> 
//Selection Sort 
//https://www.codingninjas.com/codestudio/problems/selection-sort_981162?leftPanelTab=0


//small size work good
using namespace std;
void display(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";

    }
    cout<<endl;
}

void selectionSort(vector<int>& arr, int n)
{   
  for(int i =0;i<n-1;i++){
       int minindex= i;
      for(int j=i+1;j<n;j++){
          if(arr[j]<arr[minindex])
          {
              minindex =j;
          }
          
      }
      swap(arr[minindex],arr[i]);
  }
}



int main(){
    vector <int> v {9,1,8,5,3,2};
   display(v);
   selectionSort(v,6);
   display(v);

}