#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using namespace std;
using LL = long long;

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int max_v = 0;
    LL sum = 0LL;
    for(int i = 0; i < N; i++) {
        max_v = max(max_v, A[i]);
        sum += A[i];
    }

    if(N > 3) {
        cout << 1LL * max_v * N << '\n';
        return;
    }

    
    LL ans = sum;
    if(N == 2) {
        ans = max(ans, 2LL * abs(A[0] - A[1]));
    } else {
        ans = max(ans, 3LL * A[0]);     
        ans = max(ans, 3LL * A[2]);
        ans = max(ans, 3LL * abs(A[0] - A[2]));
        ans = max(ans, 3LL * abs(A[0] - A[1]));
        ans = max(ans, 3LL * abs(A[1] - A[2]));

        ans = max(ans, 2LL * abs(A[0] - A[1]) + A[2]);
        ans = max(ans, 2LL * abs(A[1] - A[2]) + A[0]);
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
