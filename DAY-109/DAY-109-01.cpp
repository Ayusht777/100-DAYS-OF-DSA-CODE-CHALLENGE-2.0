
#include <bits/stdc++.h> 

using namespace std;
long long  fact(long n){// long for big range
  
  // base case
  if(n==0 || n==1){
    return n;
      
  }

  cout<<n<<endl;
  //small prombel  = fact(n-1)
 // badi problem = n * fact(n-1)
  return( n * fact(n-1) );
}


int main(){
    //factorila using recusrion
   long x;
   cin>>x;
   cout<<fact(x);

}