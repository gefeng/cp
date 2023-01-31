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

    vector<LL> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < Q; i++) {
        LL K;
        cin >> K;

        LL lo = 1;
        LL hi = (LL)2e18;
        LL res = 0LL;

        while(lo <= hi) {
            LL mid = (lo + hi) >> 1LL;

            auto it = upper_bound(A.begin(), A.end(), mid);

            LL cnt = mid - (LL)(it - A.begin());
            
            if(cnt >= K) {
                res = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        cout << res << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
