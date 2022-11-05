
#include <bits/stdc++.h> 
//1752. Check if Array Is Sorted and Rotated
//https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/


using namespace std;
void display(vector <int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";

    }
    cout<<endl;
}


vector<int> reverse(vector<int> a){
    int s=0;
    int e =a.size()-1;
    while(s<e){
        swap(a[s++],a[e--]);
    }
    return a;
          
 }         
vector<int> findArraySum(vector<int> &a,int n, vector<int> &b,int m){
                        
	int i = n-1;
    int j= m-1;
    int sum=0;
    int carry=0;
    vector <int> ans;
    while(i>=0&&j>=0){
        sum = a[i--] +b[j--] +carry;
       carry = sum/10;
        sum %=10;
        ans.push_back(sum);
    }
    while(i>=0){
        sum = a[i--]+carry;
        carry = sum/10;
        sum %=10;
        ans.push_back(sum);
    }
        while(j>=0){
        sum = b[j--]+carry;
        carry = sum/10;
        sum %=10;
        ans.push_back(sum);
        }
    
     while(carry!=0){
        sum = carry;
        carry = sum/10;
        sum %=10;
        ans.push_back(sum);
        }
    ans = reverse(ans);
    return ans;
    
    
        

    
}
 



     





int main(){
   vector <int> arr1 {1,2,3,4};
   vector <int> arr2 {6,0,4};
   
  
    display(arr1); 
    display(arr2);

    display(findArraySum(arr1,4,arr2,3));
 
   
  

}