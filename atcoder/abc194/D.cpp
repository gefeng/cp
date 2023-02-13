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

    double ans = 0.0;
    for(int i = 1; i < N; i++) {
        ans += (double)N / (N - i);
    }

    cout << setprecision(20) << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
