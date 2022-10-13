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

    vector<int> A(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> B(Q, 0);
    for(int i = 0; i < Q; i++) {
        cin >> B[i];
    }

    vector<int> h(N, 0);
    int min_len = 0;
    for(int i = 0; i < N; i++) {
        min_len = max(min_len, A[i]);
        h[i] = min_len;
    }

    vector<LL> psum(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        psum[i] = psum[i - 1] + A[i - 1];
    }

    for(int i = 0; i < Q; i++) {
        auto it = upper_bound(h.begin(), h.end(), B[i]);

        int j = N;
        if(it != h.end()) {
            j = it - h.begin();
        }

        cout << psum[j] << " \n"[i == Q - 1];
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
