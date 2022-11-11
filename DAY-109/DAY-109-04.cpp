
#include <bits/stdc++.h> 

using namespace std;
void reachhome(int src,int des){// long for big range
   cout<<"source : "<<src<<" des : "<<des<<endl;
  //base case
  if(src==des){
    cout<<"ghar pucha gaya"<<endl;
    return ;
      
  }
   

  reachhome(src+1,des);


}


int main(){
    //factorila using recusrion
 
 reachhome(1,15);

}