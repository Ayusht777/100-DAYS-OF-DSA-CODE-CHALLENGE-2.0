
#include <bits/stdc++.h> 

using namespace std;
//Say Digit's

void saydigit(int n,string arr []){
    if(n==0){
        return ;
    }
    int digit = n%10;
    n = n/10;
    saydigit(n,arr);
    cout<<arr[digit] <<" ";
}

int main(){
   string arr[10] {"zero","one","two","three","four","five","six","seven","eight","nine"};
   saydigit(542,arr);
   


}