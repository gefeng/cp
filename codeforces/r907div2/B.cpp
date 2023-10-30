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
    std::vector<int> B(Q);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < Q; i++) {
        std::cin >> B[i];
    } 

    std::vector<std::vector<int>> pos(31);
    for(int i = 0; i < Q; i++) {
        pos[B[i]].push_back(i);
    }

    std::vector<int64_t> ans(N);
    for(int i = 0; i < N; i++) {
        ans[i] = A[i];
    
        int p = -1;
        while(true) {
            int nxt_p = Q;
            for(int j = 1; j <= 30; j++) {
                if(ans[i] % (1 << j) == 0) {
                    auto it = std::lower_bound(pos[j].begin(), pos[j].end(), p);
                    if(it != pos[j].end()) {
                        nxt_p = std::min(nxt_p, *it);
                    }
                }
            }

            if(nxt_p < Q) {
                p = nxt_p;
                ans[i] += (1 << (B[p] - 1));
            } else {
                break;
            }
        }

        std::cout << ans[i] << " \n"[i == N - 1];
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
