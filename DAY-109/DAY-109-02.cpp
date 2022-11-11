
#include <bits/stdc++.h> 

using namespace std;
long long  power(long n){// long for big range
  
  //base case
  if(n==0 ){
    return 1;
      
  }
  if(n==1){
    return 2;
  }


  return( 2* power(n-1) );
}


int main(){
    //factorila using recusrion
   long x;
   cin>>x;
   cout<<power(x);

}