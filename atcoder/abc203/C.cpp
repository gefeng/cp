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

    vector<pair<LL, LL>> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }

    sort(A.begin(), A.end());

    LL bal = 1LL * K;
    LL ans = 0LL;
    LL cur = 0;
    for(int i = 0; i < N; i++) {
        LL pos = A[i].first;
        LL has = A[i].second;

        LL cost = pos - cur;
        if(cost <= bal) {
            bal -= cost;
            bal += has;
            cur = pos;
            ans = max(ans, cur + bal);
        } else {
            ans = cur + bal;
            break;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
