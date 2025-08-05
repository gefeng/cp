#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        int l = i == 0 ? -1 : A[i - 1];
        int r = i == N - 1 ? -1 : A[i + 1];
        if(A[i] > l && A[i] > r) {
            ans += A[i];
        }
        if(A[i] < l && A[i] < r) {
            ans -= A[i];
        }
    }


    auto update = [&](int i, int add) {
        int l = i == 0 ? -1 : A[i - 1];
        int r = i == N - 1 ? -1 : A[i + 1];
        
        if(A[i] > l && A[i] > r) {
            ans += (add ? 1 : -1) * A[i]; 
        }
        if(A[i] < l && A[i] < r) {
            ans += (add ? -1 : 1) * A[i];
        }
    };
    
    std::cout << ans << '\n';

    for(int i = 0; i < Q; i++) {
        int L, R;
        std::cin >> L >> R;
        L -= 1;
        R -= 1;

        if(L == R) {
            std::cout << ans << '\n';
            continue;
        }

        for(int j = -1; j <= 1; j++) {
            if(L + j >= 0 && L + j < N) {
                update(L + j, 0);
            }
        }
        for(int j = -1; j <= 1; j++) {
            if(R + j >= 0 && R + j < N && R + j != L && R + j != L + 1) {
                update(R + j, 0);
            }
        }
        
        std::swap(A[L], A[R]);

        for(int j = -1; j <= 1; j++) {
            if(L + j >= 0 && L + j < N) {
                update(L + j, 1);
            }
        }
        for(int j = -1; j <= 1; j++) {
            if(R + j >= 0 && R + j < N && R + j != L && R + j != L + 1) {
                update(R + j, 1);
            }
        }

        std::cout << ans << '\n';
    }
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
