#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const LL INF = (LL)2e18;

void run_case() {
    int N, L;
    cin >> N >> L;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    LL ans = INF;
    for(int i = 0; i < N; i++) {
        LL cand = 2LL * L;
        LL meet = 1LL * L - A[i];        
        
        auto r = lower_bound(A.begin(), A.end(), meet);
        auto l = r - 1;

        if(r == A.end()) {
            cand += 2LL * abs(meet - (*l));
        } else if(r == A.begin()) {
            cand += 2LL * abs(meet - (*r));
        } else {
            cand += 2LL * min(abs(meet - (*l)), abs(meet - (*r)));
        }

        ans = min(ans, cand);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
