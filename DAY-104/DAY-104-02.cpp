
#include <bits/stdc++.h> 
//125. Valid Palindrome
//https://leetcode.com/problems/valid-palindrome/description/


using namespace std;
void display(vector <int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";

    }
    cout<<endl;
}


bool isPalindrome(string s) {
	int start=0, end=s.length()-1;
	while(start<end) {
		if (!isalnum(s[start])) start++;
		else if (!isalnum(s[end])) end--;
		else {
			if (tolower(s[start++])!=tolower(s[end--])) return false;
		}
	}
	return true;
}
 
     





int main(){
    string s ="NooN";
    cout<<s<<endl;
    cout<<isPalindrome(s);
   

}