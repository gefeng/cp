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

    vector<pair<LL, LL>> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }

    auto cmp = [](const auto& a, const auto& b) {
        LL x = 2LL * a.first + a.second;
        LL y = 2LL * b.first + b.second;
        return x > y;
    };

    sort(A.begin(), A.end(), cmp);

    LL sum_a = 0LL;
    LL sum_t = 0LL;
    for(int i = 0; i < N; i++) {
        sum_a += A[i].first;
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        sum_a -= A[i].first;
        sum_t += A[i].first + A[i].second;
        if(sum_t > sum_a) {
            ans = i + 1;
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
