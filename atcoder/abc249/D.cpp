#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const int MAX = 200000;

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    array<int, 200001> cnt{0};
    for(int x : A) {
        cnt[x] += 1;
    }

    // time complexity: O(M * (M / 1 + M / 2 + M / 3...)) = O(M * logM);
    LL ans = 0LL;
    for(int a = 1; a <= MAX; a++) {
        for(int b = 1; b < MAX / a; b++) {
            ans += 1LL * cnt[a] * cnt[b] * cnt[a * b];
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
