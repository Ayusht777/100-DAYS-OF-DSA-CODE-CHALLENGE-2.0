
#include <bits/stdc++.h> 
//merge a two sorted array


using namespace std;
void display(int arr [],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";

    }
    cout<<endl;
}

void merge2sortedarr(int arr1 [],int n,int arr2[],int m,int arr3[])
{

  int i =0;
  int j =0;
  int k=0;
  while (i<n&&j<m)
  {
    if(arr1[i]<arr2[j]){
        arr3[k++] = arr1[i++];
    }
    else{
        arr3[k++] = arr2[j++];
    }
  }

  while (i<n)
  {
    arr3[k++] =arr1[i++];
  }
  while (j<m)
  {
    arr3[k++] =arr2[j++];
  }

  
  


}




int main(){
    int arr1[5] {1,3,5,7,9};
    int arr2[3] {2,4,6};
    int arr3 [8] {0};
    display(arr1,5);
    display(arr2,3);

    merge2sortedarr(arr1,5,arr2,3,arr3);
    display(arr3,8);
   
  

}