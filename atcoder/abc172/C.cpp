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
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> A(N);
    vector<int> B(M);

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < M; i++) {
        cin >> B[i];
    }

    vector<LL> prefix_A(N + 1, 0LL);
    vector<LL> prefix_B(M + 1, 0LL);

    for(int i = 1; i <= N; i++) {
        prefix_A[i] = prefix_A[i - 1] + A[i - 1];
    }

    for(int i = 1; i <= M; i++) {
        prefix_B[i] = prefix_B[i - 1] + B[i - 1];
    }

    int ans = 0;
    for(int i = 0; i <= N; i++) {
        LL sum = prefix_A[i];

        if(sum > K) {
            break;
        }

        auto it = upper_bound(prefix_B.begin(), prefix_B.end(), K - sum); 

        ans = max(ans, i + (int)(it - prefix_B.begin() - 1));
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
