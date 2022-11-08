
#include <bits/stdc++.h> 

// SUM OF ROW IN 2D ARRAY

using namespace std;

void Sumofrow(int arr[][3] ,int r,int c){
     vector <int> sum;

   for (int i = 0; i < r; i++)
   {   
        int s =0;
     for (size_t j = 0; j < c; j++)
     {
        s = arr[i][j] +s;
     }
     cout<<s<<endl;
     sum.push_back(s);
     
   }
      
   int maxi = INT_MIN;
   int rowindex= -1;
   for(int x=0 ;x<sum.size();x++){
    if(sum[x]>maxi)
    {
        maxi =sum[x];
        rowindex = x;

    }
    cout<<sum.at(x)<<" ";
   }
  cout<<endl;
  cout<<"max number is "<<maxi<<" the index is "<<rowindex;

}
     





int main(){
   int arr [3][3] {9,8,3,4,5,6,111,0,9};
   Sumofrow(arr,3,3);

}