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
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<LL> psum(N + 1, 0LL);
    for(int i = 1; i <= N; i++) {
        psum[i] = psum[i - 1] + A[i - 1];
    }

    LL ans = 0LL;
    LL max_sum = -INF;
    LL pre_pos = 0LL;
    for(int i = 0; i < N; i++) {
        ans = max(ans, pre_pos + max_sum);

        pre_pos += psum[i + 1];
        max_sum = max(max_sum, psum[i + 1]);

        ans = max(ans, pre_pos);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
