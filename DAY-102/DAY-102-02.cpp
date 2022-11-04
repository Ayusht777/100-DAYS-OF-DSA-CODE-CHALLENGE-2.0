
#include <bits/stdc++.h> 
//Reverse a  array
//https://www.codingninjas.com/codestudio/problems/reverse-the-array_1262298?leftPanelTab=1


using namespace std;
void display(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";

    }
    cout<<endl;
}

vector <int> reverseArray(vector<int> arr , int m)
{
	int s= m+1;
    int e = arr.size()-1;
    
    while(s<=e){
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
    
    return arr;
}




int main(){
    vector <int> v {9,1,8,5,3,2};
   display(v);
   vector <int> v1 = reverseArray(v,2); 
   display(v1);

}