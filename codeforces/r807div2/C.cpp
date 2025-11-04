#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, C, Q;
    std::cin >> N >> C >> Q;
    
    std::string S;
    std::cin >> S;

    std::vector<std::pair<int64_t, int64_t>> A(C);
    for(int i = 0; i < C; i++) {
        std::cin >> A[i].first >> A[i].second;
        A[i].first -= 1;
        A[i].second -= 1;
    }

    for(int i = 0; i < Q; i++) {
        int64_t K;
        std::cin >> K;
        
        int64_t p = K - 1;
        int64_t len = N;
        int j = 0;
        for(; j < C; j++) {
            if(len > p) {
                break;
            }
            len += A[j].second - A[j].first + 1;
        }
        j -= 1;

        while(j >= 0) {
            auto [l, r] = A[j];
            int64_t nlen = len - (r - l + 1);
            int64_t offset = len - 1 - p;
            int64_t np = r - offset >= l ? r - offset : p;
            p = np;
            len = nlen;
            j -= 1;
        }

        assert(p < N);
        std::cout << S[p] << '\n';
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
