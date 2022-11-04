
#include <bits/stdc++.h> 
//Reverse a  array


using namespace std;
void display(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";

    }
    cout<<endl;
}

vector <int> reversearr(vector<int> arr)
{   
  int s =0;
  int e =arr.size()-1;
  while (s<=e)
  {
    swap(arr[s],arr[e]);
    s++;
    e--;
  }
  return arr;
  
}



int main(){
    vector <int> v {9,1,8,5,3,2};
   display(v);
  vector <int>r = reversearr(v);
   display(r);

}