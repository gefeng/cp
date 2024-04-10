#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> M >> N;
    
    std::vector<int> A(N);
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] -= 1;
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
        B[i] -= 1;
    }

    std::vector<int> diff(M, 0);
    int cnt_good = 0;
    for(int i = 0; i < N; i++) {
        if((B[i] - A[i] + M) % M >= (M + 1) / 2) {
            cnt_good += 1;
        } else {
            if(B[i] < A[i]) {
                diff[A[i]] += 1;
                diff[0] += 1;
                diff[B[i]] -= 1;
            } else {
                diff[A[i]] += 1;
                diff[B[i]] -= 1;
            }
        }
    }

    std::vector<int> f(M, 0);
    int sum = 0;
    for(int i = 0; i < M; i++) {
        sum += diff[i];
        f[i] = sum; 
    }

    int ans = 0;
    int m = M % 2 == 0 ? M / 2 : M / 2 + 1;
    if(M % 2 == 0) {
        for(int i = 0; i < m; i++) {
            int cnt = f[i] + f[i + M / 2];
            ans = std::max(ans, cnt);
        }
    } else {
        for(int i = 0; i < m; i++) {
            int cnt = f[i] + f[i + M / 2];
            ans = std::max(ans, cnt);
            cnt = f[i] + f[(i + M / 2 + 1) % M];
            ans = std::max(ans, cnt);
        }
    }

    std::cout << ans + cnt_good << '\n';
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
