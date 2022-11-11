
#include <bits/stdc++.h> 

using namespace std;
//Count Ways To Reach The N-th Stairs 
//https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650
//tlde margya sla dp sa hoyga
int countDistinctWays(int nStairs) {
    if(nStairs<0){
        return 0;
    }
    if(nStairs==0){return 1;}
    
    return ( countDistinctWays(nStairs-1)+countDistinctWays(nStairs-2));
}

int main(){
    //factorila using recusrion
   for(int i=0;i<10;i++){
    cout<<countDistinctWays(i)<<" ";
   }


}