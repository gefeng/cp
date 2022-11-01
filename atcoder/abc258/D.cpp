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
    int N, X;
    cin >> N >> X;
    
    vector<pair<int, int>> A(N, {0, 0});
    for(int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }

    LL ans = INF;
    LL sum = 0LL;
    for(int i = 0; i < N && X; i++) {
        sum += 1LL * A[i].first + A[i].second;
        ans = min(ans, sum + 1LL * (X - 1) * A[i].second);
        X--;
    } 

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
