
#include <bits/stdc++.h> 
//Modular Exponentiation 
//https://www.codingninjas.com/codestudio/problems/modular-exponentiation_1082146?leftPanelTab=0

using namespace std;

int modularExponentiation(int x, int n, int m) {
	long long r=1;
    while(n>0){
        if(n&1){
            //odd case
            r = (1LL*(r)*(x)%m)%m;
            
        }
        x =(1LL*(x)%m*(x)%m)%m;
        n = n>>1;
    }
    return r;
}

int main(){
 int a ,b;
 cin>>a>>b;

 cout<<modularExponentiation(a,b,5)<<endl;



}