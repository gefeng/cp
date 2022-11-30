#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> d(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < i; j++) {
            d[j] += A[i - 1];
            d[j] %= 360;
        }
    }

    sort(d.begin(), d.end());

    int ans = 360 - d[N];
    for(int i = 1; i <= N; i++) {
        ans = max(ans, d[i] - d[i - 1]);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
