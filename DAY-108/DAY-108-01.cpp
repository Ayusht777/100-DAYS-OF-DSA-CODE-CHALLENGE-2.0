
#include <bits/stdc++.h> 

using namespace std;

int getsum(int *arr,int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum = sum +arr[i];
    }
    return sum;

}

int main(){
    //ref to variable
    int i =10;
    int &j=i;
    cout<<i<<endl;
    i++;
    cout<<i<<endl;
    j++;
    cout<<j<<endl;
  int n{0};
  cout<<"enter the numbers of element :";
  cin>>n;

//dynamic memory allocation
   int *arr = new int [n];

   for(int i =0;i<n;i++){
    cin>>arr[i];
   }
   cout<<getsum(arr,n);
  delete arr;

}