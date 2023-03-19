#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

void run_case() {
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<LL> psum(N + 1, 0LL);
    for(int i = 1; i <= N; i++) {
        psum[i] = psum[i - 1] + A[i - 1];
    }

    for(int i = 0; i < Q; i++) {
        int L, R, K;
        cin >> L >> R >> K;
        R -= 1;
        L -= 1;

        LL sum = psum[R + 1] -  psum[L];
        
        bool res = (psum[N] - sum + (1LL * K * (R - L + 1))) % 2 == 1;
        cout << (res ? "YES" : "NO") << '\n';
    } 
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
