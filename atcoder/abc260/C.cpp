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
    int N, X, Y;
    cin >> N >> X >> Y;

    vector<LL> cnt_r(N + 1, 0LL);
    vector<LL> cnt_b(N + 1, 0LL);
    cnt_r[N] = 1LL;

    for(int i = N; i > 1; i--) {
        cnt_r[i - 1] += cnt_r[i];
        cnt_b[i] += cnt_r[i] * X;

        cnt_r[i - 1] += cnt_b[i];
        cnt_b[i - 1] += cnt_b[i] * Y;
    }

    cout << cnt_b[1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
