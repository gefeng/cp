#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
using LL = long long;

void run_case() {
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> A(N);
    vector<int> B(K);

    for(int i = 0; i < K; i++) {
        cin >> B[i];
        B[i] -= 1;
    }

    for(int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }

    double ans = 0.0;
    for(int i = 0; i < N; i++) {
        double min_d = 2e9;
        for(int j : B) {
            double d = sqrt(((double)A[i].first - A[j].first) * ((double)A[i].first - A[j].first) + 
                ((double)A[i].second - A[j].second) * ((double)A[i].second - A[j].second));
            min_d = min(min_d, d);
        }
        ans = max(ans, min_d);
    }

    cout << setprecision(19) <<ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
