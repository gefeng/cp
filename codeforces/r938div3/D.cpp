#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<int> A(N);
    std::vector<int> B(M);
    std::map<int, int> m1;
    std::map<int, int> m2;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
        m1[B[i]] += 1;
    }

    int ans = 0;
    int cnt = 0;
    for(int l = 0, r = 0; r < N; r++) {
        if(r - l + 1 > M) {
            //m2[A[l]] -= 1;
            if(m1.find(A[l]) != m1.end()) {
                int x = m2[A[l]];
                int y = m1[A[l]];
                if(x <= y) {
                    cnt -= 1;
                }
            }
            if(--m2[A[l]] == 0) {
                m2.erase(A[l]);
            }
            l += 1;
        } 

        m2[A[r]] += 1;
        if(m1.find(A[r]) != m1.end()) {
            int x = m2[A[r]];
            int y = m1[A[r]];
            if(x <= y) {
                cnt += 1;
            }
        }

        if(r - l + 1 == M) {
            ans += cnt >= K ? 1 : 0;
        }
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
