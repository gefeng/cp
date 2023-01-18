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

    LL K;
    cin >> K;

    vector<pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(A.begin(), A.end());

    vector<LL> ans(N, 0);
    for(int i = 0; i < N; i++) {
        ans[i] = K / N;
    }

    LL rem = K % N;
    for(int i = 0; i < rem; i++) {
        ans[A[i].second] += 1LL;
    }

    for(int i = 0; i < N; i++) {
        cout << ans[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
