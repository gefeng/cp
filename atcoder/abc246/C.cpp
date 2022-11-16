#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

using namespace std;
using LL = long long;

void run_case() {
    int N, K, X;
    cin >> N >> K >> X;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < N && K; i++) {
        if(A[i] > X) {
            int need = min(A[i] / X, K);
            A[i] -= need * X;
            K -= need;
        }
    }

    sort(A.begin(), A.end());

    for(int i = N - 1; i >=0 && K; i--) {
        A[i] = 0LL;
        K -= 1;
    }

    LL ans = accumulate(A.begin(), A.end(), 0LL);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
