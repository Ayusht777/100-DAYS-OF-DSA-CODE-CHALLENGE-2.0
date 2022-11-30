#include <bits/stdc++.h>

using namespace std;
//First non-repeating character in a stream
//First Unique Character In A String 
//https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
   public:
    string FirstNonRepeating(string A) {
        unordered_map<char, int> count;
        queue<int> q;
        string ans = "";

        for (int i = 0; i < A.length(); i++) {
            char ch = A[i];
            // increase the count
            count[ch]++;

            // qeue push karo

            q.push(ch);
            // check for reapting and non reaptring
            while (!q.empty()) {
                if (count[q.front()] > 1) {
                    q.pop();
                    // remove this reapted element
                } else {
                    // Non reapting elemrnt
                    ans.push_back(q.front());
                    break;
                }
            }
            if (q.empty()) {
                ans.push_back('#');
            }
        }

        return ans;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}