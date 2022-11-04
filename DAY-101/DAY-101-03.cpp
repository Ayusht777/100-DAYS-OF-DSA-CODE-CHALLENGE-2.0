#include<iostream>
#include <bits/stdc++.h> 
//Insertataion Sort 
//https://www.codingninjas.com/codestudio/problems/insertion-sort_3155179?leftPanelTab=1

//small size work good
using namespace std;
void display(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";

    }
    cout<<endl;
}

void insertionSort(int n, vector<int> &arr){
    
    for(int i =1;i<n;i++){
        int temp = arr[i];
        int j = i-1;
        for(;j>=0;j--){
            if(arr[j]>temp){
                arr[j+1] =arr[j];
            
                
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;
    }
 
}


int main(){
    vector <int> v {9,1,8,5,3,2};
   display(v);
   insertionSort(6,v);
   display(v);

}