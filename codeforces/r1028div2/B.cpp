#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(998244353);

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::vector<int64_t> p_2(N, 1);
    for(int i = 1; i < N; i++) {
        p_2[i] = p_2[i - 1] * 2 % MOD;
    }

    int m_a = -1;
    int m_b = -1;
    int p_a = -1;
    int p_b = -1;
    for(int i = 0; i < N; i++) {
        int64_t res = 0;
        if(m_a < A[i]) {
            m_a = A[i];
            p_a = i;
        }
        if(m_b < B[i]) {
            m_b = B[i];
            p_b = i;
        }

        if(m_a > m_b) {
            res = (p_2[m_a] + p_2[B[i - p_a]]) % MOD;
        } else if(m_b > m_a) {
            res = (p_2[m_b] + p_2[A[i - p_b]]) % MOD;
        } else {
            int x = A[i - p_b];
            int y = B[i - p_a];
            res = x >= y ? (p_2[m_b] + p_2[x]) % MOD : (p_2[m_a] + p_2[y]) % MOD;
        }

        std::cout << res << " \n"[i == N - 1];
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
