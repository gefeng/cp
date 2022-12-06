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
    int N, K;
    cin >> N >> K;

    vector<LL> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    LL lo = 0LL;
    LL hi = accumulate(A.begin(), A.end(), 0LL) / K;
    LL ans = 0LL;
    while(lo <= hi) {
        LL mid = (lo + hi) >> 1LL;
        
        LL need = mid * K;
        LL sum = 0LL;
        for(int i = 0; i < N; i++) {
            sum += min(A[i], mid);
        }
        
        if(sum >= need) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
