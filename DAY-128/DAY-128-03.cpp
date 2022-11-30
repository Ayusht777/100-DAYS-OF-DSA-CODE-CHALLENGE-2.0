#include <bits/stdc++.h>

using namespace std;
//First negative integer in every window of size k
//https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
vector<long long> printFirstNegativeInteger(long long int A[], long long int N,long long int K) {
    deque<long long int> d;
    vector<long long> ans;
    // process for firtd k window
    for (int i = 0; i < K; i++) {
        if (A[i] < 0) {
            d.push_back(i);
        }
    }

    // store answer of first k elment

    if (d.size() > 0) {
        ans.push_back(A[d.front()]);

    } else {
        ans.push_back(0);
    }
    // procees for reamming window
    for (int i = K; i < N; i++) {
        if (!d.empty() && i - d.front() >= K) {
            d.pop_front();
        }
        if (A[i] < 0) {
            d.push_back(i);
        }

        // store answer

        if (d.size() > 0) {
            ans.push_back(A[d.front()]);

        } else {
            ans.push_back(0);
        }
    }
    return ans;
}

int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

