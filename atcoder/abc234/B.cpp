#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> B(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    double ans = 0.0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            ans = max(ans, sqrt((A[i] - A[j]) * (A[i] - A[j]) + (B[i] - B[j]) * (B[i] - B[j])));
        }
    }

    cout << setprecision(20) << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
