#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using namespace std;
using LL = long long;

void run_case() {
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i].first;
    }

    for(int i = 0; i < N; i++) {
        cin >> A[i].second;
    }

    map<int, int> m;
    for(int i = 0; i < N; i++) {
        m[A[i].second] += 1;
    }
    
    sort(A.begin(), A.end());
    
    bool ans = true;
    LL d = K;
    for(int i = 0; i < N; ) {
        if(K == 0) {
            ans = false;
            break;
        }
        while(i < N && A[i].first <= d) {
            if(--m[A[i].second] == 0) {
                m.erase(A[i].second);
            }

            i += 1;
        }

        K = max(0, K - m.begin()->first);
        d += K;
    }
    
    cout << (ans ? "YES" : "NO") << '\n';
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
