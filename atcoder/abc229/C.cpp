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
    int N, W;
    cin >> N >> W;

    vector<pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }

    sort(A.begin(), A.end());

    LL ans = 0LL;
    for(int i = N - 1; i >= 0 && W; i--) {
        int d = min(W, A[i].second);

        ans += 1LL * d * A[i].first;
        W -= d;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
