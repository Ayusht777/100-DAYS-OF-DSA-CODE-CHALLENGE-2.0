
#include <bits/stdc++.h> 

using namespace std;
//1910. Remove All Occurrences of a Substring
 //https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/


 string removeOccurrences(string s, string part) {
        while(s.length()!=0&&s.find(part)<s.length())
        {
            s.erase(s.find(part),part.length());
        }
        return s;

    }

     





int main(){
    string x = "testbestrest";

    string p = "es";
    cout<<x<<endl;
    cout<<p<<endl;
    cout<<removeOccurrences(x,p)<<endl;

}