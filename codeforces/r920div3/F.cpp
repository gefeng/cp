#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

void run_case() {
    int N, Q;
    std::cin >> N >> Q;
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int sqr = (int)std::sqrt(N);
    std::vector<std::vector<std::vector<int64_t>>> psum(sqr + 1);
    std::vector<std::vector<std::vector<int64_t>>> psum_psum(sqr + 1);

    for(int d = 1; d <= sqr; d++) {
        for(int st = 0; st < d; st++) {
            int64_t sum = 0;
            psum[d].emplace_back();
            psum[d].back().push_back(0);
            for(int i = st; i < N; i += d) {
                sum += A[i];
                psum[d].back().push_back(sum);
            }

            int size = psum[d].back().size();
            psum_psum[d].emplace_back();
            psum_psum[d].back().resize(size + 1, 0);
            for(int i = 0; i < size; i++) {
                psum_psum[d].back()[i + 1] = psum_psum[d].back()[i] + psum[d].back()[i];
            }
        }
    }

    for(int i = 0; i < Q; i++) {
        int S, D, K;
        std::cin >> S >> D >> K;

        S -= 1;
        int64_t res = 0;
        
        if(D > sqr) {
            int64_t serial = 1;
            for(int i = S; i < N && serial <= K; i += D) {
                res += A[i] * serial;
                serial += 1;
            }
        } else {
            int st = S % D;
            std::vector<int64_t>& v1 = psum[D][st];
            std::vector<int64_t>& v2 = psum_psum[D][st];
            
            int l = S / D;
            int r = l + (K - 1) + 1;
            res = (r - l) * v1[r] - (v2[r] - v2[l]);
        }

        std::cout << res << " \n"[i == Q - 1];
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
