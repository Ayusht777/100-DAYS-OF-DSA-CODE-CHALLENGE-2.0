
#include <bits/stdc++.h> 
//Merge Two Sorted Arrays
//https://www.codingninjas.com/codestudio/problems/ninja-and-sorted-arrays_1214628?leftPanelTab=3


using namespace std;
void display(vector <int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";

    }
    cout<<endl;
}



vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    int j=0;
	for(int i = m;i<=m+n-1;i++){
  
        arr1[i] = arr2[j];
        j++;
        
        
    }

    sort(arr1.begin(),arr1.end());
    return arr1;  
}



int main(){
   vector <int> arr1 {1,2,3,0,0};
    vector <int> arr2 {4,5};
  
    display(arr1);
    display(arr2);

    vector <int> arrx = ninjaAndSortedArrays(arr1,arr2,3,2);
    display(arrx);
   
  

}