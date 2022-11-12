
#include <bits/stdc++.h> 

using namespace std;
//power 
int power(int a,int b){
  //base case
  if(b==0){
    return 1;
  }
  if(b==1){
    return a;
  }
  int ans = power(a,b/2);
  if(b%2==0){
    return ans*ans;
  }
  else{
    //if b is odd
    return (a*ans*ans);
  }
}

  




int main(){

  cout<<power(2,10);

  
 
 
 


}