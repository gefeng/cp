#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K, Q;
    std::cin >> N >> K >> Q;

    std::vector<int> ans(N, -1);
    std::vector<std::tuple<int, int, int>> A(Q);
    for(int i = 0; i < Q; i++) {
        auto& [c, l, r] = A[i];
        std::cin >> c >> l >> r;
    }

    std::ranges::sort(A);

    for(auto [c, l, r] : A) {
        l -= 1;
        r -= 1;
        if(c == 1) {
            for(int i = l; i <= r; i++) {
                ans[i] = -3;
            }
        }
    }

    for(auto [c, l, r] : A) {
        l -= 1;
        r -= 1;
        if(c == 2) {
            for(int i = l; i <= r; i++) {
                if(ans[i] == -3) {
                    ans[i] = K + 1;
                }
            }
        }
    }

    for(int i = 0; i < N; i++) {
        if(ans[i] == -3) {
            ans[i] = K;
        }
    }

    for(auto [c, l, r] : A) {
        l -= 1;
        r -= 1;
        if(c == 2) {
            std::vector<int> seen(K, 0);
            for(int i = l; i <= r; i++) {
                if(ans[i] >= 0 && ans[i] < K) {
                    seen[ans[i]] = 1;
                }
            }
         
            int j = 0;
            for(int i = l; i <= r; i++) {
                if(ans[i] == -1) {
                    while(j < K && seen[j]) {
                        j += 1;
                    }
                    if(j < K) {
                        seen[j] = 1;
                        ans[i] = j++;
                    }
                }
            }
            
            for(int i = 0; i < K; i++) {
                assert(seen[i] == 1);
            }
        }
    }

    for(auto [c, l, r] : A) {
        l -= 1;
        r -= 1;
        if(c == 2) {
            for(int i = l; i <= r; i++) {
                if(ans[i] == -1) {
                    ans[i] = 0;
                }
            }
        }
    }

    for(int i = 0; i < N; i++) {
        if(ans[i] < 0) {
            ans[i] = 0;
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
