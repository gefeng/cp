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

    vector<int> B(Q);
    for(int i = 0; i < Q; i++) {
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    
    vector<LL> psum(N + 1, 0LL);
    for(int i = 1; i <= N; i++) {
        psum[i] = psum[i - 1] + A[i - 1];
    }

    for(int q : B) {
        auto it = upper_bound(A.begin(), A.end(), q);
        
        int k = (int)(it - A.begin());
        
        LL res = 1LL * k * q - psum[k] + psum[N] - psum[k] - 1LL * (N - k) * q;
        cout << res << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
