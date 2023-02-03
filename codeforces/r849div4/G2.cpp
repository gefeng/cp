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

const LL INF = (LL)2e18;

void run_case() {
    int N, C;
    cin >> N >> C;

    vector<int> A(N);
    vector<int> B(N);
    vector<pair<int, int>> P;
    P.reserve(2 * N);
    for(int i = 0; i < N; i++) {
        int X;
        cin >> X;
        A[i] = X + i + 1;
        B[i] = X + N - i;
        P.emplace_back(X + i + 1, i + 1);
        P.emplace_back(X + N - i, -i - 1);
    }

    sort(P.begin(), P.end());

    vector<bool> used(N + 1, false);
    int ans = 0;
    int bal = C;
    bool ok = false;
    for(auto& p : P) {
        int c = p.first;
        int i = p.second;
        if(!used[abs(i)] && bal >= c) {
            bal -= c;
            used[abs(i)] = true;
            ans += 1;
            // exist at least one step from (0, 0)
            if(i > 0) {
                ok = true; 
            }
        }
    }

    if(ok) {
        cout << ans << '\n';
        return;
    }
    
    ans = 0;

    vector<pair<int, int>> picked;
    for(int i = 1; i <= N; i++) {
        if(used[i]) {
            picked.emplace_back(B[i - 1], i - 1);
        }
    }
    
    sort(picked.begin(), picked.end());

    int sz = picked.size();
    vector<LL> psum(sz + 1, 0LL);
    for(int i = 1; i <= sz; i++) {
        psum[i] = psum[i - 1] + picked[i - 1].first;
    }

    auto bs = [&](int from, int to, LL x) -> int {
        int lo = 1;
        int hi = to - from + 1; 
        int ans = 0;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;

            if(psum[from + mid] - psum[from] <= x) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    };

    for(int i = 0; i < sz; i++) {
        auto& p = picked[i];
        int c = p.first;
        int j = p.second;
        int bal = C - A[j];

        if(bal >= 0) {
            int l = bs(0, i - 1, bal);
            int r = bs(i + 1, sz - 1, bal - psum[l]);

            ans = max(ans, l + r + 1);
        }
    }

    for(int i = 0; i < N; i++) {
        if(!used[i + 1] && C >= A[i]) {
            int bal = C - A[i]; 
            int cnt = bs(0, sz - 1, bal);
            ans = max(ans, cnt + 1);
        }
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
