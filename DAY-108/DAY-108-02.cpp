
#include <bits/stdc++.h> 

using namespace std;


int main(){
  //2d dymaci array
  int n{0};
  cout<<"enter the numbers of element :";
  cin>>n;

  int **arr = new int*[n];

  for (int i = 0; i < n; i++)
  {
     arr[i] = new int[n];//allcoatin 1-d array
  }

  for (size_t i = 0; i < n; i++)
  {
    for (size_t j = 0; j < n; j++)
    {
      cin>>arr[i][j];
    }
    
  }

  for (size_t i = 0; i < n; i++)
  {
  for (size_t j = 0; j <n; j++)
  {
    cout<<arr[i][j]<<" ";
  }
   cout<<endl;
  }

for (size_t i = 0; i < n; i++)
{
  //delte array
  delete []arr[i];
}


  delete []arr;
  
  

  


}