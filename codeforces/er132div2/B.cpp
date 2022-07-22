#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
using LL = long long;

void run_case() {
    int n = 0;
    int m = 0;
    
    cin >> n;
    cin >> m;

    vector<int> A(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<LL> psum(n + 1, 0);
    vector<LL> ssum(n + 1, 0);

    for(int i = 2; i <= n; i++) {
        psum[i] = psum[i - 1] + max(0, A[i - 2] - A[i - 1]);
    }

    for(int i = n - 2; i >= 0; i--) {
        ssum[i] = ssum[i + 1] + max(0, A[i + 1] - A[i]);
    }

    vector<LL> ans(m, 0);
    for(int i = 0; i < m; i++) {
        int s, t;
        cin >> s >> t;

        ans[i] = s < t ? psum[t] - psum[s] : ssum[t - 1] - ssum[s - 1];
    }

    for(LL x : ans) {
        cout << x << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);        // de-sync with c stream
    cin.tie(0);                         // disable flushing of std::cout
    
    run_case();
}
