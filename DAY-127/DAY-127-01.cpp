#include <bits/stdc++.h>
#include<queue>
using namespace std;
//Queue

int main(){
   
   queue <int> q;

   for(int  i=1;i<4;i++){
    q.push(i*i);
   }

   cout<<"the siz eof queue is "<<q.size()<<endl;

   cout<<"at the font "<<q.front()<<endl;
     q.pop();
    cout<<"at the font "<<q.front()<<endl;

    if(q.empty()){
      cout<<"it is emmpty"<<endl;
    }
    else{
      cout<<"not empty"<<endl;
    }

   


}
