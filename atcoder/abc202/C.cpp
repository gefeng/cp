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

    vector<int> A(N);
    vector<int> B(N);
    vector<int> C(N);

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        cin >> B[i];
    }

    for(int i = 0; i < N; i++) {
        cin >> C[i];
    }

    vector<int> cnt(N + 1, 0);
    for(int j = 0; j < N; j++) {
        cnt[B[C[j] - 1]] += 1;
    }

    LL ans = 0LL;
    for(int i = 0; i < N; i++) {
        ans += cnt[A[i]]; 
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
