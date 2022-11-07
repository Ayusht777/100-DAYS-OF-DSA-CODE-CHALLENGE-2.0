
#include <bits/stdc++.h> 
//1047. Remove All Adjacent Duplicates In String

//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/
using namespace std;
 string removeDuplicates(string s) {
        int i = 0, n = s.length();
        for (int j = 0; j < n; ++j, ++i) {
            s[i] = s[j];
            if (i > 0 && s[i - 1] == s[i]) // count = 2
                i -= 2;
        }
        return s.substr(0, i);

 }





int main(){
    string s1 = "abbaca";

    cout<<removeDuplicates(s1);
    
}