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

    vector<int> cnt(N + 1, 2);
    cnt[1] = 1;

    for(int i = 2; i <= N; i++) {
        for(int j = i + i; j <= N; j += i) {
            cnt[j] += 1;
        }
    }

    LL ans = 0LL;
    for(int i = 1; i <= N; i++) {
        ans += 1LL * i * cnt[i];
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
