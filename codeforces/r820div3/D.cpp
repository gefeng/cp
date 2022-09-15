#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N;
    cin >> N;
    
    vector<int> A(N, 0);
    vector<int> B(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        cin >> B[i];
    }

    vector<int> neg;
    vector<int> pos;
    neg.reserve(N);
    pos.reserve(N);
    for(int i = 0; i < N; i++) {
        int d = B[i] - A[i];
        if(d >= 0) {
            pos.push_back(d);
        } else {
            neg.push_back(d);
        }
    }

    sort(pos.begin(), pos.end(), greater<int>());
    sort(neg.begin(), neg.end());

    int ans = 0;
    int pos_p = 0;
    int neg_p = 0;
    int n = pos.size();
    int m = neg.size();
    while(pos_p < n && neg_p < m) {
        if(-neg[neg_p] > pos[pos_p]) {
            neg_p++;
        } else {
            ans++;
            pos_p++;
            neg_p++;
        }
    }

    while(pos_p + 1 < n) {
        ans++;
        pos_p += 2;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
