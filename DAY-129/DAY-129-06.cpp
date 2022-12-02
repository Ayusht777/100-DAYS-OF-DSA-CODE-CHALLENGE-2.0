#include <bits/stdc++.h> 
using namespace std;

//Sum of minimum and maximum elements of all subarrays of size k
//https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/


int solve (int *arr,int n,int k){
   deque <int> maxi(k);
   
   deque <int> mini(k);

   //addition of  fisrt k size windows
   for (size_t i = 0; i < k; i++)
   {
      while (!maxi.empty()&&arr[maxi.back()]<=arr[i])
      {
        maxi.pop_back();
      }
      while (!mini.empty()&&arr[mini.back()]>=arr[i])
      {
        mini.pop_back();
      }
      maxi.push_back(i);
      mini.push_back(i);
      
      
   }

   int ans=0;
   for (size_t i = k; i < n; i++)
   {
      ans =ans + arr[maxi.front()] +arr[mini.front()];
      //next windows
      //removal
        while (!maxi.empty() && i-maxi.front()>=k)
        {
          maxi.pop_front();
        }
        while (!mini.empty() && i-mini.front()>=k)
        {
          mini.pop_front();
        }
       //adititon
      while (!maxi.empty()&&arr[maxi.back()]<=arr[i])
      {
        maxi.pop_back();
      }
      while (!mini.empty()&&arr[mini.back()]>=arr[i])
      {
        mini.pop_back();
      }
      maxi.push_back(i);
      mini.push_back(i);

      
   }
   //make sure to consdier last windows

   ans =ans + arr[maxi.front()] +arr[mini.front()];
   
   
  return ans;


}





int main(){
  int arr [7] = {2, 5, -1, 7, -3, -1, -2};
  cout<<solve(arr,7,4)<<endl;

}