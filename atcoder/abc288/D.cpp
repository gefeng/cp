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
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<vector<LL>> psum(K, vector<LL>(N + 1, 0LL)); 
    for(int r = 0; r < K; r++) {
        for(int i = 0; i < N; i++) {
            psum[r][i + 1] = psum[r][i] + (i % K == r ? 1LL * A[i] : 0LL);
        }
    }

    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;
        L -= 1;
        R -= 1;

        bool ok = true;
        for(int r = 0; r < K; r++) {
            if(psum[r][R + 1] - psum[r][L] != psum[0][R + 1] - psum[0][L]) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "Yes" : "No") << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
