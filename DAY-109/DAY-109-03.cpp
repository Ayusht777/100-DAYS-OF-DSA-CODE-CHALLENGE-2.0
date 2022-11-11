
#include <bits/stdc++.h> 

using namespace std;
void print(long n){// long for big range
  
  //base case
  if(n==0 ){
    return ;
      
  }
   
  cout<<n<<" ";
//trail recusrion
  print(n-1);


}


int main(){
    //factorila using recusrion
   long x;
   cin>>x;
   print(x);

}