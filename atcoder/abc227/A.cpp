#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, K, A;
    cin >> N >> K >> A;

    K %= N;
    if(K == 0) {
        K = N;
    }

    if(N - A + 1 >= K) {
        cout << A + K - 1 << '\n';
    } else {
        cout << K - (N - A + 1) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
