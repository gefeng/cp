#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const LL INF = (LL)2e18;

void run_case() {
    int N, M;
    cin >> N >> M;

    vector<LL> A(N);
    vector<LL> B(N);

    for(int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    auto f = [](LL a, LL b, LL x, LL y) {
        return a + b * y + (y + 1LL) * y / 2LL * x; 
    };

    LL a = 0LL;
    LL b = 0LL;
    LL ans = -INF;
    for(int i = 0; i < N; i++) {
        if(A[i] < 0 && b > 0) { 
            LL t = b / -A[i];
            if(t < B[i]) {
                ans = max(ans, f(a, b, A[i], t));
            }
        }

        ans = max(ans, f(a, b, A[i], 1LL));
        ans = max(ans, f(a, b, A[i], B[i]));

        a = f(a, b, A[i], B[i]);
        b += 1LL * A[i] * B[i];
    } 

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
