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
    int N;
    cin >> N;

    vector<pair<int, int>> A(N, {0, 0});
    for(int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
        if(A[i].first > A[i].second) {
            swap(A[i].first, A[i].second);
        }        
    }

    auto cmp = [](const auto& a, const auto& b) {
        return a.second < b.second;
    };

    sort(A.begin(), A.end(), cmp);

    if(N == 1) {
        cout << 2LL * A[0].first + 2LL * A[0].second << '\n';
        return;
    }
    
    LL ans = 2LL * A[0].first + A[0].second;
    for(int i = 1; i < N; i++) {
        ans += 2LL * A[i].first;
        ans += A[i].second - A[i - 1].second;
    }

    ans += A[N - 1].second;

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
