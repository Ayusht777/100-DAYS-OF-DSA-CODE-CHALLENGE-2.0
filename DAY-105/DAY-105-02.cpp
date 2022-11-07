
#include <bits/stdc++.h> 

using namespace std;

//Maximum Occuring Character
//https://practice.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1


char  countword(string s)
{
    int arr[26]{0};
    for(int i =0;i<s.size();i++){
        int n =0;
        // if(s[i]>='a' && s[i]<='z'){
            n = s[i]-'a';
        // }
        // else{
        //     n = s[i]-'A';
        // }
        arr[n]++;
    }

    int maxi=-1,ans=0;
    for(int i=0;i<26;i++){
        if(maxi<arr[i]){
            ans =i;
            maxi =arr[i];

        }

    }

    char fans = ans+'a';
    return fans;

    
    
}



     





int main(){
    string x = "testsample";
    cout<<x<<endl;
    cout<<countword(x)<<endl;

}