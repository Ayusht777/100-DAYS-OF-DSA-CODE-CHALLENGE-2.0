#include<iostream>
#include <bits/stdc++.h> 
//Bubble Sort 
//https://www.codingninjas.com/codestudio/problems/bubble-sort_980524?leftPanelTab=1


//small size work good
using namespace std;
void display(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";

    }
    cout<<endl;
}


void bubbleSort(vector<int>& arr, int n)
{   
    for(int i = 1;i<n;i++){
        for(int j =0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

//opmitmize version
#include <bits/stdc++.h> 
void bubbleSortOPTM(vector<int>& arr, int n)
{   
    for(int i = 1;i<n;i++){
        bool swapchecker =false;
        for(int j =0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapchecker =true;
            }
        }
        if(swapchecker ==false){
            break;
        }
    }
}



int main(){
    vector <int> v {9,1,8,5,3,2};
   display(v);
   bubbleSort(v,6);
   display(v);

}