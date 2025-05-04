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
    std::cin >> N >> M;

    std::vector<int> A(N);
    std::vector<int> B(M);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    std::vector<std::vector<int>> a(N, B);

    int ans = 0;
    for(int b = 8; b >= 0; b--) {
        bool seen = false;
        for(int i = 0; i < N; i++) {
            if(A[i] & (1 << b)) {
                seen = true;
            }
        }

        if(!seen) {
            continue;
        }

        int cnt = 0;
        for(int i = 0; i < N; i++) {
            if(!(A[i] & (1 << b))) {
                cnt += 1;
                continue;
            }

            bool found = false;
            for(int x : a[i]) {
                if(!(x & (1 << b))) {
                    found = true;
                    break;
                }
            }

            if(found) {
                cnt += 1;
            }
        }

        if(cnt == N) {
            for(int i = 0; i < N; i++) {
                if(!(A[i] & (1 << b))) {
                    continue;
                }
                
                std::vector<int> nxt;
                for(int x : a[i]) {
                    if(!(x & (1 << b))) {
                        nxt.push_back(x);
                    }
                }
                a[i] = std::move(nxt);
            } 
        } else {
            ans |= (1 << b);
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
