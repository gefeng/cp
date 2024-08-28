#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    int64_t X, K;
    std::cin >> N >> X >> K;

    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end(), std::greater<int64_t>());
    
    int64_t h = X * K;
    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] < h) {
            ans += 1;
            h = A[i];
        } 
    }

    int p = -1;
    for(int i = 0; i < N; i++) {
        if(A[i] < X) {
            p = i;
            break;
        }
    }

    if(p == -1) {
        std::cout << ans << '\n';
        return;
    }

    std::vector<int64_t> a;
    std::vector<int64_t> b;
    for(int i = N - 1; i >= 0; ) {
        int j = i;
        while(i >= 0 && A[j] == A[i]) {
            i -= 1;
        }
        if(j >= p) {
            if(j - i > 1) {
                a.push_back(A[j]);
            }
        } else {
            a.push_back(A[j]);
        }
    }

    for(int i = N - 1; i >= p; ) {
        int j = i;
        while(i >= p && A[j] == A[i]) {
            i -= 1;
        }
        b.push_back(A[j]);
    }

    h = X;
    int64_t cnt = 0;
    for(int i = p; i < N; ) {
        int j = i;
        while(i < N && A[j] == A[i]) {
            i += 1;
        }

        cnt += 1;
        h = A[j];

        int64_t extra = std::lower_bound(a.begin(), a.end(), h * K) - std::lower_bound(a.begin(), a.end(), h);
        auto it = std::lower_bound(b.begin(), b.end(), h);
        extra += it - b.begin(); 
        ans = std::max(ans, cnt + extra);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
