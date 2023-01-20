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
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    LL ans = 1LL * (N - 1) * N / 2LL;

    map<int, int> m;
    for(int i = N - 1; i >= 0; i--) {
        int cnt = 0;
        if(m.find(A[i]) != m.end()) {
            cnt = m[A[i]];
        }

        ans -= cnt;
        m[A[i]] += 1;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
