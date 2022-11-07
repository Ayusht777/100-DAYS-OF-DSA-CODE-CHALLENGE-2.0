
#include <bits/stdc++.h> 
//443. String Compression

//https://leetcode.com/problems/string-compression/description/
using namespace std;
int compress(vector<char>& chars) {
        int i=0;
        int ansindex =0;
        while(i<chars.size()){
            int j=i+1;
            ///counter loop
            while(j<chars.size()&&chars[i]==chars[j])
            {
                j++;
            }
            chars[ansindex++] =chars[i];
            int count = j-i;
            if(count>1){
                string nc = to_string(count);
                for(auto c:nc){
                    chars[ansindex++] =c;
                }

            }
            i=j;



        }
         return ansindex;

          }





int main(){
    vector <char> s1 {'a','a','b','b','c'};

    cout<<compress(s1);
    
}