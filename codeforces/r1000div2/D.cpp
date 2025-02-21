#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    std::vector<int> B(M);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    if(N < M) {
        std::swap(A, B);
        std::swap(N, M);
    }

    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());

    std::vector<int> seg_a;
    std::vector<int> seg_b;

    int k_max = 0;
    if(M * 2 <= N) {
        k_max = M;
    } else {
        k_max = N - M;
        int left = M + M - N;
        k_max += left / 3 * 2;
        k_max += left % 3 == 2 ? 1 : 0;
    }

    std::cout << k_max << '\n';
    
    for(int l = 0, r = N - 1; l < r; l += 1, r -= 1) {
        seg_a.push_back(A[r] - A[l]); 
    } 

    for(int l = 0, r = M - 1; l < r; l += 1, r -= 1) {
        seg_b.push_back(B[r] - B[l]);
    }

    int n = seg_a.size();
    int m = seg_b.size();
    std::vector<int64_t> psum_a(n + 1, 0);
    std::vector<int64_t> psum_b(m + 1, 0);

    for(int i = 0; i < n; i++) {
        psum_a[i + 1] = psum_a[i] + seg_a[i];
    }

    for(int i = 0; i < m; i++) {
        psum_b[i + 1] = psum_b[i] + seg_b[i];
    }

    for(int k = 1; k <= k_max; k++) {
        int lo = std::max(0, 2 * k - M);
        int hi = std::min(N - k, k);
        int64_t res = -1;

        while(hi - lo >= 3) {
            int m_1 = lo + (hi - lo) / 3;
            int m_2 = hi - (hi - lo) / 3;

            int64_t s_1 = psum_a[m_1] + psum_b[k - m_1];
            int64_t s_2 = psum_a[m_2] + psum_b[k - m_2];
            if(s_1 < s_2) {
                lo = m_1;
            } else {
                hi = m_2;
            }
        }
        
        for(int i = lo; i <= hi; i++) {
            res = std::max(res, psum_a[i] + psum_b[k - i]);
        }
        
        std::cout << res << " \n"[k == k_max];
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
