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
    int N, K;
    cin >> N >> K;

    vector<LL> A(N, 0LL);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    LL ans = 0LL;
    for(int i = 0; i < K; i++) {
        LL max_v = 0LL;
        for(int j = 1; j <= N; j++) {
            if(j % K == i) {
                max_v = max(max_v, A[j - 1]);
            }
        }

        ans += max_v;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
