#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const double EPS = 1e-5;

void run_case() {
    int N;
    cin >> N;

    vector<pair<int, int>> A(N);
    double sum_d = 0.0;
    for(int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
        sum_d += A[i].first;
    }

    double lo = 0.0;
    double hi = 1e9;
    double ans_t = 0.0;
    double ans_d = 0.0;
    while(hi - lo >= EPS) {
        double mid = (lo + hi) / 2.0;

        double d1 = 0.0;
        double d2 = 0.0;
        double t = mid;
        for(int i = 0; i < N; i++) {
            double need = min(t, (double)A[i].first / A[i].second);
            t -= need;
            d1 += need * A[i].second;
        }

        t = mid;
        for(int i = N - 1; i >= 0; i--) {
            double need = min(t, (double)A[i].first / A[i].second);
            t -= need;
            d2 += need * A[i].second;
        }

        if(d2 + d1 - sum_d >= EPS) {
            ans_t = mid;
            ans_d = d1;
            hi = mid;
        } else {
            lo = mid;
        }
    }

    cout << setprecision(20) << ans_d << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
